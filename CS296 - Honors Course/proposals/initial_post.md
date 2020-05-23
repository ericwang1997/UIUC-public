**Jan 31: Initial Proposal**

**Team member**: Vivek Mallampati (vivekm3), Eric Wang (wcwang2)

**Project overview**: We will be designing a visualization of memory allocation of all variables and functions of a program. It would be a library which would open an interactive feature on a browser, and allow users to search their keyword to keep track of where the variable is allocated.

**Purpose**: Unlike other languages such as Java and Python, C does not automatically free the memory allocated on the heap, which causes a memory leak. Since C allows users to manipulate memories directly, we want to help users visualize the memory map. This can enhance their coding experiences, such as more efficient memory usage, and making the debug process less painful.

**Workload**: 3 hours per week, but adjustable, depending on the actual progress on the project. We may be dividing up work after the first meeting with our mentor.

**Milestones**:
1. Week 6: obtaining actual memory addresses of each part of the program
2. Week 8: differentiating and categorizing each segment of memory
3. Week 13: visualization of each memory in a browser
4. Week 15: enhancing our browser, including clickable or other interactive features

**Tools**: C for memory allocation, Javascript for web design

**Difficulties**:
1. While it may be easy to differentiate heap and stack memory, it may be hard to categorize memories that are closer in the memory map.
2. When a function is called within a function, stack memory may be reused.
3. Web design may be more time consuming than we have expected. 
