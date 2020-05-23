#include "array.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdbool.h> 

typedef struct huge_{ 
	size_t huge_1; 
	char character; 
	size_t huge_3; 
} huge; 


int main(int argc, char** argv) { 
	check_usage(argc, argv); 
	void* arr = array1D(sizeof(huge), 4); 	
	
	
	for (int i = 0; i <= (int)array1D_size(arr); i++) { 
		huge* a = (huge*)array1D_get(arr, i); 
		a -> huge_1 = i+50; 
		a -> character = i+100; 
		a -> huge_3 = i+105; 
	} 
	
	
	size_t sizes[4] = {8, 1, 8, 0}; 
	char* names[4] = {"huge_1", "character", "huge_3", NULL}; 
	detail(arr, sizes, names, "Demo 4: Array struct padding"); 
	
	array1D_free(arr); 
	if (argc == 2) end(); 
	return 0; 
} 
