# get_next_line
42Cursus-get_next_line/42Lisboa

# Contents

 1. [Intro](https://github.com/mlanca-c/get_next_line#intro)
 	* [Keywords](https://github.com/mlanca-c/get_next_line#keywords)
 2. [I/O System Calls](https://github.com/mlanca-c/get_next_line#io-system-calls)
 	* [File Descriptor](https://github.com/mlanca-c/get_next_line#file-descriptor)
	* [Read Function in C](https://github.com/mlanca-c/get_next_line#read-function-in-c)
 3. [Static Variables](https://github.com/mlanca-c/get_next_line#static-variables)

# Intro

 > [subject](subject.pdf)

 The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.
 
 This project will not only allow you to add a very convenient function to your collection, but it will also allow you to learn a highly interesting new concept in C programming: ```static variables```.

 Objectives: 
 * Calling the function in a loop will read the text available on a ```file descriptor```, one line at a time until end of the file.
 * Return 1 when a line has been read, 0 when EOF has been reached, -1 when an error happened.
 * Able to manage multiple file descriptors.


## Keywords

 > [file descriptor](https://hacksland.net/c-programming-file-descriptors), [read](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/), [static variables](https://www.tutorialspoint.com/static-variables-in-c).

# I/O System Calls

## File Descriptor

 <details>

 A file descriptor (FD or fildes) is a non-negative integer - negative values are reserved for errors - that uniquely identifies an open file from the file descriptor table.

 Standard File Descriptors:
  * **0** standard input (stind): read from fd 0,
  * **1** standard output (stout): write for fd 1,
  * **2** standard error (stderr): write for fd 2.

 </details>

## Read Function in C
 ```read()``` attempts to read ```nbyte``` bytes of data from the object referenced by the descriptor ```fildes``` into the ```buffer``` pointed to by buf.
 ```c
 ssize_t read(int fildes, void *buf, size_t nbyte);
 ```

 The read() function ```returns``` the ```number of bytes``` that were actually read, ```0``` if it has reached the EOF, and ```-1``` in case of an error.

 It's iportant to understand that the **buf** needs to point to a valid memory location, with bigger or equal lenght that the specified size of bytes beind read;
 the **fildes** should be valid - returned from an open();
 **nbytes** is the requested number of bytes to read, this is not always equal to the return value of read(), since some times the read function call can read less than nbytes.

### BUFFER_SIZE

 <details>

 The ```BUFFER_SIZE``` will be used with the ```-D flag```.
 ```Shell
 -D name=definition
 ```
 Predefine ```name``` as a macro with ```definition``` being it's value.

 What happens is that this program will always have to be compiled withe the ```-D BUFFER_SIZE=<number>``` in order for the program to run.
 To avoid having to compile it always with the flag. In the header file it was added the following lines of code:
 ```c
 # ifndef BUFFER_SIZE
  # define BUFFER_SIZE 1
 # endif
 ```

 </details>

# Static Variables

 ```c
 static datatype variable_name = value;
 ```
 * **[datatype](https://codeforwin.org/2017/08/data-types-in-c-programming.html):** the datatype of variable like int, char, float etc.
 * **variable_name:** this is the name of variable given by user.
 * **value:** any value to initialize the variable. By default, it is zero.

 Static variables are declared with ```static``` keyword, they have an essential property of **preserving its value** across various function calls. Unlike ```local variables```, static variables are not allocated on C stack. Rather, they get their memory in data segment of the program.
 
 It's possible to do this project with only one static variable. This static variable will hold a line that was read with the size BUFFER_SIZE until the program ends.

