#include "array.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdbool.h> 

int main(int argc, char** argv) { 
	check_usage(argc, argv); 
	void* arr = array1D(sizeof(int), 15); 
	for (int i = 0; i < (int)array1D_size(arr); i++) { 
		int* a = (int*)array1D_get(arr, i); 
		*a = 100; 
	} 
	detail(arr, NULL, NULL, "Demo 2: Array visualization"); 
	array1D_free(arr); 
	if (argc == 2) end(); 
	return 0; 
} 
