#============== CS 570 ASSIGNMENT 1 ~ MakeFile ============== 

#Project Creators: Bashier Dahman and Matthew Morisky 
#RedID's: Bashier ~ 819804018 || Matthew ~ 820150975 
#Account Usernames: Bashier ~ cssc2153 || Matthew ~ cssc2135
#Class Information: CS 570, Summer 2020
#Assignment Information: Assignment #1, Process Manager
#Filename: makefile

################################################################
# Make File for creating / running executable named "bots.exe" #
#            Bashier Dahman and Matthew Morisky                #  
################################################################

# defining our compiler
CC	=	g++

# running g++ and creating the executable file / then running it
all:

	@echo	"Compiling assignment1_final.cpp"

	$(CC)	-o	bots	assignment1_final.cpp	-pthread
	
	@echo	"Now going to run the bots executable..."
	
	bots

# this will remove the bots and QUOTE.txt files to clean up the dir.
clean:
	@echo "Now removing 'bots' and 'QUOTE.txt' files"

	rm	bots	QUOTE.txt
#######################[ EOF: Makefile ]###################
