This directory contains the following directories and files

README.txt: this file
Makefile: a top-level makefile
	Run make in this directory to create a zip file called p3-submit.zip for submission.

Each directory contains a Makefile
	make
		compiles the program
	make test
		compiles the code & runs a basic sanity test
	make clean
		removes the files created by make

random:	The demo code for a shared library that overwrites the random function
	myrand.c: the replacement function
	random.c: a main program that prints 10 random numbers

hidefile: The directory for part 2 - hiding files
	hidefile.c: an empty implementation of your readdir replacement
	env.c: demo code for reading an environment variable

passgen: The directory for part 1 - password generatin
	getrandom.c: an empty implementation of your getrandom replacement
	passgen.py: the python password generator (don't modify this)
