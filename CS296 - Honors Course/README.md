**Progress report** 

**W0 (Feb 24 - Mar 2)**: 
1. Learned some X86, and found out that it is actually very similar to MIPS. 
2. Objective: Track all variable declared throughout the entire lifetime of the c program 

**W1 (Mar 3 - Mar 9)**: 
1. Focus on memory first instead of variable names, particularly those allocated on the heap 
2. Figured out how to print out the variable name (it is actually a lot simpler than expected)
3. "vector.h" import does not work for vector initialization 
4. Started writing code, but had to use function names different from malloc, realloc, calloc and free 

**W2 (Mar 10 - Mar 16)**: Midterm presentation on Mar 13 
1. Figured out that malloc MP uses fork for the system to use an alternative type of malloc and free 
2. Need makefile to link "vector.h" 
3. Would save variable name, memory usage and location in three separate vectors 

**W3 (Mar 17 - Mar 23)**: Spring break 
1. Research on objdump and its flags, retrieved assembly language from binary executable. 
2. Tried to find variable name from objdump output, not sure where to get them. 
3. Redirected output of stdout and stderr to filename. 
4. Can get variable name from main via C language macro but requires direct modification of main. 

**W4 (Mar 24 - Mar 30)**: 
1. Tried multiple variable names but objdump does not seem promising in giving variable names. 
2. Other ways of getting variable names: valgrind. 
3. Research and use mini_valgrind's mini_hacks.c to link malloc, realloc and calloc. 

**W5 (Mar 31 - Apr 6)**: Slightly changed direction after discussing with mentor 
1. Valgrind simply gets the line where the variable was declared for memory corruption or leak and slices anything before the equal sign. 
2. Valgrind still cannot get the physical location in text segment. 
3. Implement own data structure library, such as arrays, linked list, binary trees and dictionaries with additional features. 

**W6 (Apr 7 - Apr 13)**: 
1. Array initialization and free information can be redirected to file or simply the terminal. 
2. Implemented boundary tags for memory corruption detection. 
3. Metadata stored in the front boundary tag, may cause undefined behavior when user writes into that block. 
4. Not sure how to constantly check boundary tags in run time. 
5. Finished visualization for arrays of primitive types (non-structs). 
6. Additional feature for array library: checking race conditions. 

**W7 (Apr 14 - Apr 20)**: 
1. Checks the boundary tags for potential memory corruption only when the array is freed. 
2. Only gives warning when boundary errors are not entirely clean instead of exiting the program because such writes may be intended. 
3. Finished visualization for arrays of structs. 
4. Moved tags metadata to global to prevent user distorting array or element size. 

**W8 (Apr 21 - Apr 27)**: 
1. T-san is an additional user feature which is added in Makefile. Would not be added to implementation. 
2. Added padding feature which allows users to input real sizes of each element of struct. 
3. Value of elements in struct can recognize its type based on variable size. 
4. Polish code and prepare for final presentation. 

**W9 (Apr 28 - May 4)**: Final presentation on May 1 
1. Will not include mini_valgrind modification in final presentation, but will incorporate its features in array implementation. 
2. Final code and slides updated on repo. 
