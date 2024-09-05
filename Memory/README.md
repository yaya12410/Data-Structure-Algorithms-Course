Memory is divided into smaller addressable units called byte.\
A computer has 3 main blocks which are the CPU, Main Memory, Hard Disk.\
Assume the data and the program are stored on the hard disk and the user runs a program that needs some data, so here is what happens:\
The program is sent to the main memory on the code section to run it, and the data that is used by the program that the program process is sent to the main memory on the stack section and this part of the stack section is called the stack frame of the main function. The process of deciding the size needed to perform the previous is called static memory allocation as the size was decided during the compile time, and it will be used during execution time.\
Every byte has its own address.

Assuming that int takes 2 bytes for easier explanation, and float takes 4 bytes and we have the following program:\
void main() \
{\
    int a;\
    float b;\
}\
Then the size of the memory required by a function is decided at compile time only, and this size will be taken from the stack memory and this part from stack memory in execution time is called the stack frame of the main function, and this is called static memory allocation as it was decided in compile time what size do we need.
