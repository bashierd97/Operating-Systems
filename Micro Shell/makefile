#============== CS 570 ASSIGNMENT 2 ~ MakeFile ============== 

#Project Creators: Matthew Morisky and Bashier Dahman
#RedID's: Matthew ~ 820150975 || Bashier ~ 819804018
#Account Usernames: Matthew ~ cssc2135 || Bashier ~ cssc2153
#Class Information: CS 570, Summer 2020
#Assignment Information: Assignment #2, MiniShell
#Filename: makefile

####################################################################
# Make File for creating / running executable named msh_assignment #
#              Matthew Morisky and Bashier Dahman                  #  
####################################################################

# defining our compiler
CC	=	g++

# running g++ and creating the executable file / then running it
all:

	@echo	"Compiling assignment2_main.cpp"

	$(CC)	-o	msh	assignment2_main.cpp
	
	@echo	"Now going to run the Mini Shell"
	
	./msh

# this will remove the bots and QUOTE.txt files to clean up the dir.
clean:
	@echo "Now removing 'msh' executable"

	rm	msh
#######################[ EOF: Makefile ]###################
