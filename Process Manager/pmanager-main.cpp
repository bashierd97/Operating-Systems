/* 
============== Process Manager Main File ============== 

Project Creators: Bashier Dahman
Process Manager Main File
Filename: pmanager-main.cpp

*/

// including our process manager header file
#include "pmanager-header.h"

// main function
int main() {

    /// open our text file
    ofs.open("QUOTE.txt");

    // get process ID
    pid = getpid();
    
    // Write the process ID to the file
    ofs << "Process ID: " <<  pid << " \r \n";
 
    // close the text file
    ofs.close();

    /* initialize a private semaphore */
    pshared = 0;
    value = 1;
    ret = sem_init(&FLAG, pshared, value);

    // initialize 7 private threads
    pthread_t threads[NUM_THREADS];
    int ptc;   // stands for pthread_create
    int i;     // int i for iterating 
    int joinNumber;

    // for loop for creating the threads, creating threads[1-7]
    for(i = 1; i <= NUM_THREADS; i++) {
       cout << "Creating thread, in main(): " << i << endl;
       
       // pthread_create method for creating threads that call the printQuote method
       ptc = pthread_create(&threads[i], NULL, printQuote, (void *)i);
       
      // if statement incase ptc cannot be created,
      // will display error message and exit prog.
        if (ptc != 0) {
          cout << "Error: Unable to create thread," << ptc << endl;
          exit(-1);
       }
    }

  // for loop to wait / block for all threads to complete
  for(i = 1; i <= NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
    joinNumber++;
    }
  
    // print a friendly statement to the console indicating thread's are complete
    cout << "All thread's are complete" << endl;
    cout << "Please check the 'QUOTE.txt' file, to see what was written! \n" << "Thank You and Good Bye!" << endl;

    // destroy the semaphore gracefully 
    int sem_destroy(sem_t *FLAG);

    // exit all threads
    pthread_exit(NULL);

    // return 0 if program compiled successfully
    return 0;

} // main program bracket

