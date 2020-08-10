# Process Manager Program

This program will manage multiple threads, all writing to a shared file. The program will implement several chat bots. Each chat bot will run in their own thread, simultaneously but asynchronously with each other. Each bot shall write the specified text message to one, common shared resource, a file named QUOTE.txt. In order to prevent the data from getting corrupted by other bots, the bots shall use Semaphores as an appropriate IPC mechanism/algorithm. <br />[**NOTE:** This programs follows POSIX Standards, and must be compiled / used on a UNIX Machine.]

## Functionality of Program

When the program starts, it shall do the following:
- Create a file, named QUOTE.txt, in the current directory (cwd).
- Have the running process write it’s pid (Process ID) followed by a Carriage Return and Newline in to the file & close the file QUOTE.txt
- Create a semaphore named FLAG which the threads will use to manage access to the file QUOTE.txt.
- Create 7 threads. Use the POSIX version of threads (i.e., pthread_create())
- Block/wait for all seven threads to complete their work.
- Once all threads are done, destroy the semaphore, then exit gracefully, printing a friendly message to the console

## Functionality of Threads

Each thread shall perform the following (note, each thread is running concurrently):
- Periodically (even numbered threads - once every two seconds, odd numbered threads – once every 3 seconds) get the semaphore FLAG; once the thread has FLAG, it will proceed to do the following:
  - Open the file QUOTE.txt and write the thread’s tid (thread id) followed by “The Quote” (followed by   - Carriage Return and Newline)
  - Write to the console (print to stdout) “Thread <thread id> is running” followed by a newline
  - Close the file QUOTE.txt
  - Release the semaphore FLAG
- Repeat the above 7 times (they run a total of 8 times).
- EXIT

### QUOTES FOR BOTS TO USE

**Even numbered threads:** “Controlling complexity is the essence of computer programming.
--Brian Kernigan <br />
**Odd numbered threads:** “Computer science is no more about computers than astronomy is about
telescopes.”
--Edsger Dijkstra

## To compile and execute

For simplicity I included a makefile, all that you would need to type in the terminal is ```make```, and the makefile will compile and execute the program. ```make clean``` will clean up the directory and remove any unnecessary files.

If you'd like to compile the program and run the program *manually*, begin by compiling with ```g++ -o bots pmanager-main.cpp -pthread``` then ```./bots```
