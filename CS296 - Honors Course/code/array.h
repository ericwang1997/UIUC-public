#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdbool.h> 

void* array1D(size_t size, size_t count); 
void array1D_free(void* arr); 
size_t array1D_size(void* arr); 
void* array1D_get(void* arr, int index); 
void print(char* name, size_t* size, void* location); 
void detail(void* arr, size_t* sizes, char** names, char* debug); 
void check_usage(int argc, char** argv); 
void redirect(char* filename); 
void end(); 
