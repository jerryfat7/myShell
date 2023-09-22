build/myShell:shell.o
	gcc -o build/myShell shell.o
shell.o:shell.c
	gcc -c shell.c
clean:
	rm shell.o myShell