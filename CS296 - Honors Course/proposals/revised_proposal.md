**Feb 24: Revised Proposal**

**Team member**: Eric Wang (wcwang2)

**Mentors**: Steven and Ophir

**Project overview**: I will design a visualization of memory allocation by retrieving and displaying the variable names of all the memory I allocated throughout the lifetime of the program. This could give users more information on where their variables are allocated on the memory map, which can be beneficial for their debugging process, or allowing more efficient usage or memory.

**Tasks**:
1. Understanding how variable names are saved in memory, and how to use assembly language to retrieve them
2. Obtaining the information of each variable, such as when it is declared, freed, written and read
3. When errors occurred, such as double free or writing to read-only memory, display appropriate warning message with detailed information
4. If possible, give users suggestions on how they can solve their error, or how they can make their memory allocation more effective

**Milestones**:
1. **W7**: Finish research and finalize the scope of the project with mentors, start learning x86
2. **W8**: Finish learning x86, try to retrieve variable names from text segment
3. **W9**: Midterm presentation: Able to display all variable names used in a C file
4. **W10**: Spring break: I will be staying on campus, and I hope to get when each variable is used and freed
5. **W11**: Getting how much memory each variable is used, and when it is written or read
6. **W12**: Able to handle flawed C programs, and display appropriate error message
7. **W13**: Flexible week
8. **W14**: Flexible week 
9. **W15**: Final Presentation

**Flexible week**: I honestly believe that the milestones above is very likely to be delayed, because the concepts are relatively new to me. I will be talking to mentors every week to make sure that I am in the right direction. If I am able to finish the milestones each week though, I will be designing suggestions of how to improve the C program.

**Difficulties**:
1. My experiences in assembly languages is limited to MIPS from CS 233, which means it will take sometime for me to learn and familiarize with X86.
2. There are both advantages and disadvantages of working on my own. Since this topic requires a lot of research, I would spend a lot of time googling.
3. Keeping track of stack data when functions are called within a function.
