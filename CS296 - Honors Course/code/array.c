#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdbool.h> 

typedef struct tag_ { 
	size_t location; 	// This is the location of the array (user return) 
	char size; 			// This is the size of each element in the array 
	size_t count; 		// This is the count of elements in the array 
} tag; 

static tag list[1024]; 
static size_t ii = 0; 
static FILE* f; 

void* array1D(size_t size, size_t count) { 
	size_t need = size * (count + 2); 
	void* ptr = malloc(need); 
	if (!ptr) printf("Your array initialization was unsuccessful.\n"); 
	memset(ptr, 0, need); 
	void* result = (char*)ptr + size; 
	list[ii].location = (long)result; 
	list[ii].size = size; 
	list[ii].count = count; 
	ii++; 
	fprintf(stderr, "You successfully allocated an 1D array (%zu elements of %zu bytes) at %p\n", count, size, result); 
	return result; 
} 

void array1D_free(void* arr) { 
	tag* my_tag = NULL; 
	for (size_t i = 0; i < ii; i++) { 
		tag this_tag = list[i]; 
		if (this_tag.location == (long)arr) { 
			my_tag = &this_tag; 
			break; 
		} 
	} 
	if (!my_tag) { 
		printf("Bad free!\n"); 
		return; 
	} 
	bool warning = false; 
	char* head = (char*)arr - my_tag -> size; 
	size_t count = my_tag -> count; 
	size_t size = my_tag -> size; 
	my_tag -> location = 0; 
	my_tag -> size = 0; 
	my_tag -> count = 0; 
	char* tempt = head; 
	void* potential = NULL; 
	while (tempt < (char*)head + size) { 
		if (*tempt) { 
			warning = true; 
			potential = tempt; 
			break; 
		} 
		tempt++; 
	} 
	char* end = (char*)arr + size * (count + 1); 
	tempt = end - size; 
	while (tempt < end) { 
		if (*tempt) { 
			warning = true; 
			potential = tempt; 
			break; 
		} 
		tempt++; 
	} 
	free(head); 
	if (warning) fprintf(stderr, "You may have a memory corruption at %p\n", tempt); 
	fprintf(stderr, "You freed an array of size %zu at %p\n", size * count, arr); 
} 

size_t array1D_size(void* arr) { 
	tag* my_tag = NULL; 
	for (size_t i = 0; i < ii; i++) { 
		tag this_tag = list[i]; 
		if (this_tag.location == (long)arr) { 
			my_tag = &this_tag; 
			break; 
		} 
	} 
	if (!my_tag) { 
		printf("BAD!\n"); 
		return 0; 
	} 
	return my_tag -> count; 
} 

void* array1D_get(void* arr, int index) { 
	tag* my_tag = NULL; 
	for (size_t i = 0; i < ii; i++) { 
		tag this_tag = list[i]; 
		if (this_tag.location == (long)arr) { 
			my_tag = &this_tag; 
			break; 
		} 
	} 
	if (!my_tag) { 
		printf("BAD!\n"); 
		return 0; 
	} 
	return (char*)arr + my_tag -> size * index; 
} 

void print(char* name, size_t* size, void* location) { 
	if (*size == 1) { 
		char* this = (char*)location; 
		printf("\t%s: \t %c \t %ld \t %p\n", name, *this, *size, (void*)this); 
	} 
	else if (*size == 2) { 
		short* this = (short*)location; 
		printf("\t%s: \t %u \t %ld \t %p\n", name, *this, *size, (void*)this); 
	} 
	else if (*size == 4) { 
		int* this = (int*)location; 
		printf("\t%s: \t %d \t %ld \t %p\n", name, *this, *size, (void*)this); 
	} 
	else if (*size == 8) { 
		size_t* this = (size_t*)location; 
		printf("\t%s: \t %lu \t %ld \t %p\n", name, *this, *size, (void*)this); 
	} 
	else { 
		printf("Not supported!\n"); 
	} 
} 

void print_non(size_t index, size_t size, void* location) { 
	if (size == 1) { 
		char* this = (char*)location; 
		printf("\t%zu: \t %c \t %zu \t %p\n", index, *this, size, (void*)this); 
	} 
	else if (size == 2) { 
		short* this = (short*)location; 
		printf("\t%zu: \t %u \t %zu \t %p\n", index, *this, size, (void*)this); 
	} 
	else if (size == 4) { 
		int* this = (int*)location; 
		printf("\t%zu: \t %d \t %zu \t %p\n", index, *this, size, (void*)this); 
	} 
	else if (size == 8) { 
		size_t* this = (size_t*)location; 
		printf("\t%zu: \t %lu \t %zu \t %p\n", index, *this, size, (void*)this); 
	} 
	else { 
		printf("Not supported!\n"); 
	} 
} 

void nonstruct(void* arr, size_t size, size_t count) { 
	fprintf(stdout, "\tindex\t value \t size \t location\n"); 
	for (size_t i = 0; i < count; i++) { 
		char* this = (char*)arr + size * i; 
		print_non(i + 1, size, this); 
	} 
	fprintf(stdout, "\n"); 
} 

size_t* change_size(size_t* sizes) { 
	size_t max = *sizes; 
	size_t* tempt = sizes; 
	size_t count = 0; 
	while (*tempt) { 
		if (*tempt > max) max = *tempt; 
		count++; 
		tempt++; 
	} 
	tempt = sizes; 
	size_t offset = *sizes; 
	size_t offsets[count]; 
	offsets[0] = 0; 
	for (size_t i = 1; i < count; i++) { 
		offsets[i] = offset; 
		if (offsets[i] % sizes[i]) offsets[i] += (sizes[i] - (int)offsets[i] % (int)sizes[i]); 
		offset = offsets[i] + sizes[i]; 
	} 
	size_t* size2 = calloc(sizeof(size_t), count + 1); 
	for (size_t i = 0; i < count - 1; i++) size2[i] = offsets[i + 1] - offsets[i]; 
	size2[count - 1] = sizes[count - 1]; 
	if ((int)offset % (int)max) size2[count - 1] += (max - (int)offset % (int)max); 
	size2[count] = 0; 
	return size2; 
} 

void detail(void* arr, size_t* sizes, char** names, char* debug) { 
	if (debug) printf("\n%s\n\n", debug); 
	tag* my_tag = NULL; 
	for (size_t i = 0; i < ii; i++) { 
		tag this_tag = list[i]; 
		if (this_tag.location == (long)arr) { 
			my_tag = &this_tag; 
			break; 
		} 
	} 
	if (!my_tag) { 
		printf("The array you are trying to visualize does not exist!\n"); 
		return; 
	} 
	if (!sizes) { 
		nonstruct(arr, my_tag -> size, my_tag -> count); 
		return; 
	} 
	size_t* tempt = sizes; 
	size_t max = *sizes; 
	while (*tempt) { 
		if (*tempt > max) max = *tempt; 
		tempt++; 
	} 
	size_t size = my_tag -> size; 
	size_t count = my_tag -> count; 
	size_t given_sizes = 0; 
	size_t* size2 = change_size(sizes); 
	tempt = size2; 
	while (*tempt) { 
		given_sizes += *tempt; 
		tempt++; 
	} 
	if (size != given_sizes) { 
		puts("BAD SIZE"); 
		return; 
	} 
	for (size_t i = 0; i < count; i++) { 
		fprintf(stdout, "Element %zu: \t\t value \t size \t location\n", i + 1); 
		char* element = (char*)arr + size * i; 
		size_t* element_size = sizes; 
		size_t* real_size = size2; 
		char** element_name = names; 
		char* tempt = element; 
		while (*element_size) { 
			print(*element_name, element_size, tempt); 
			tempt += *real_size; 
			element_size++; 
			element_name++; 
			real_size++; 
		} 
		printf("\n"); 
	} 
	free(size2); 
} 

void redirect(char* filename) { 
	f = fopen(filename, "w"); 
	dup2(fileno(f), fileno(stderr)); 
}  

void check_usage(int argc, char** argv) { 
	if (argc == 2 && strcmp(argv[1], "-h") == 0) { 
		fprintf(stdout, "Usage: \n\n\t ./main [filename]\n\n"); 
		fprintf(stdout, "The option \"filename\" gives you the option to redirect stderr to your specified filename. "); 
		fprintf(stdout, "If the option is used, use redirect(argv[1]) at the start and end() at the end. \n\n"); 
		fprintf(stdout, "To visualize your array, call the function: \n\n"); 
		fprintf(stdout, "void detail(void* arr, size_t* sizes, char** names, char* debug)\n\n"); 
		fprintf(stdout, "\tarr\t- pointer to your array\n"); 
		fprintf(stdout, "\tsizes\t- array of sizes, ends with 0\n"); 
		fprintf(stdout, "\tnames\t- array of names, ends with NULL\n"); 
		fprintf(stdout, "\tdebug\t- option to include a debug message\n\n"); 
		exit(1); 
	} 
	else if (argc == 1) return; 
	else if (argc == 2) redirect(argv[1]); 
	else exit(1); 
} 

void end() { 
	fclose(f); 
} 
