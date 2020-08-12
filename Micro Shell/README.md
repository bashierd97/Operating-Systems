# Micro Shell Program

This program will emulate a linux shell but with limited capabilities. 

## Functionality

This program will provide the following functions:
- Provide a command line interface using the machine's username (i.e.: "user%") and wait for the user to type in a file name
- When the user enters a filename at the prompt and hits the “enter” key, the program shall read the filename entered and determine if the file is an executable file. If it isn’t, then print a useful error message to the user and then return to command line interface mentioned above (display a new prompt and wait for user input). If it is an executable file, then create a new process and run this program in the new process.
- Please **NOTE**: The program will not provide all built-in shell functions, only a limited amount. Such as pipes, ```cat```, ```grep```, ```sort``` and several others, including ```exit``` which will close the program and terminate.

## Design Decisions

I designed 2 functions, one to gather a stream of input from the user and store their commands in a command array, and the other to build our pipes and execute the commands given to the pipes. I built a 2d array to hold all the user commands. As our buffer has a size of 1024, I figured we needed an array that can hold at most 512 pipes. This is because that would be the maximum possible amount of pipes the program can hold. This must be initialized at run time so we created the entire array in our mini_shell(). I decided to call this function mini_shell() as it performs most of the heavy lifting and allows our actual main file to be much cleaner.

One thing we had to include was signalling a SIGQUIT, if the user wanted to exit the program. Following this we take care of any zombie children processes and finally exiting successfully. This allowed the program to function as needed, and acted as a complete mini shell.


### To Compile & Execute (Make File)

You may use the makefile to compile and execute the program with ease. To do so, just type ```make``` in the command line interface and the makefile will do the rest.

```make clean``` will clean any extra files.

### To Compile & Execute (Manually)

To compile the program using g++, type ```g++ -o msh msh_main.cpp``` and execute the program in the same directory using ```./msh```
