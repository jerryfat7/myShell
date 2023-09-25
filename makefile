build/myShell:shell.o myStr.o
	gcc -o build/myShell shell.o myStr.o
shell.o:shell.c
	gcc -c shell.c
myStr.o:myStr.c
	gcc -c myStr.c
clean:
	rm shell.o myShell