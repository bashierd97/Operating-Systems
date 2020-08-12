/*
============== MicroShell Main File ==============

Project Creators: Bashier Dahman
Assignment Information: MicroShell Program
Filename: msh_main.cpp

*/

#include "msh_header.h"

pid_t pid_new;
int status;

int main(void) {

    while (true) {

        if ((pid_new = fork()) < 0) { //Forking pid_new, and checking if fork failed
            perror("pipe");
        }

        if (pid_new == 0) { //Checking if the fork was successful

            if (mini_shell() == 1) { //Calls the function instantiating the MiniShell and determines if 1 was returned

                //If a quitStatus of 1 is returned the user would like to exit the MiniShell
                cerr << "Ending the MiniShell...\n";

                // determined to use SIGQUIT rather than SIGINT to end the program because it is cleaner
                //kill(pid_new, SIGINT);  // send an INT signal
                kill(pid_new, SIGQUIT); // Ending all child processes

                //Quiting out of all children, waiting for them to complete and exiting
                waitpid(pid_new, &status, 0); //Taking care of any lingering zombie children
                exit(0); // Exit successfully

            }

        }

        waitpid(pid_new, &status, 0); //Taking care of any lingering zombie children   

    }

}