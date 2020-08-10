#============== Process Manager MakeFile ============== 

#Project Creator: Bashier Dahman 
#Process Manager
#Filename: makefile

################################################################
# Make File for creating / running executable named "bots.exe" #
#                      Bashier Dahman		               #  
################################################################

# defining our compiler
CC	=	g++

# running g++ and creating the executable file / then running it
all:

	@echo	"Compiling pmanager-main.cpp"

	$(CC)	-o	bots	pmanager-main.cpp	-pthread
	
	@echo	"Now going to run the bots executable..."
	
	bots

# this will remove the bots and QUOTE.txt files to clean up the dir.
clean:
	@echo "Now removing 'bots' and 'QUOTE.txt' files"

	rm	bots	QUOTE.txt
#######################[ EOF: Makefile ]###################
