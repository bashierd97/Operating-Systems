/* 
============== Processs Manager Header File ============== 

Project Creators: Bashier Dahman 
Process Manager Header File
Filename: pmanager-header.h

*/

// Header File that will include 
// initilizing variables
// and function definitons 

// all libraries we will be using
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

using namespace std;

/* Initilizing Variables */

#define NUM_THREADS 7 //defining how many threads we'll have

pid_t pid;        // process ID variable
sem_t FLAG;       // semaphore named FLAG
int pshared;      
int ret;
int value;
std::ofstream ofs;    // ofstream, how we will open / close our files

/* Initilizing the semaphore */

int sem_init(sem_t *FLAG, int pshared, unsigned value);

// Function for every two seconds thread
void every2sec(long tempID){
     int x = 0;
     
     // quote that we will print out for evens
     string twosQuote = "\"Controlling complexity is the essence of computer programming.\" --Brian Kernigan";
     
     // while loop to repeat the instructions 7 times
     while(x < 8) {
     
         // locking the semaphore
         sem_wait(&FLAG);
         
         // opening "QUOTE.txt" file, and writing the quotes inside
         ofs.open("QUOTE.txt", ios::app);
         cout << "Thread " << tempID << " is running\n";
         ofs << "Thread ID " << tempID << ": " << twosQuote << " \r \n";
         // closing the file
         ofs.close();         

         // unlocking the semaphore
         sem_post(&FLAG);
         
         // delaying for 2 seconds
         sleep(2);
         x++;

     } 
    
}
// Function for every three seconds thread
void every3sec(long tempID) {
     int x = 0;
     
     // quote that we will print out for odds
     string threesQuote = "\"Computer science is no more about computers than astronomy is about telescopes.\" -Edsger Dijkstra";

    // while loop to repeat the instructions 7 times
     while(x < 8) {

         // locking the semaphore
         sem_wait(&FLAG);
         
         // opening "QUOTE.txt" file, and writing the quotes inside
         ofs.open("QUOTE.txt", ios::app);
         cout << "Thread " << tempID << " is running\n";
         ofs << "Thread ID " << tempID << ": " << threesQuote << " \r \n";
         // closing the file
         ofs.close();
         
         // unlocking the semaphore
         sem_post(&FLAG);

         // delaying for 3 seconds
         sleep(3);
         x++;

     }

}

// Function for determining if the thread ID is either even / odd 
// & if even it'll call every2sec() & if odd it'll call every3sec()
void *printQuote(void *threadID) {

   // receiving "i" from the for loop called in main
   // using it determine what the Thread ID will be
   long tempID;
   tempID = (long)threadID;

   // condition statement for determining if even / odd 
   if (tempID%2 == 0) {
       // call every2sec func
       every2sec(tempID);
     }
   else {      
     // call every3sec func
     every3sec(tempID);

   }
}