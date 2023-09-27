shell:shell.o myStr.o
	gcc shell.o myStr.o -fdiagnostics-color=always -g -o shell
shell.o:shell.c
	gcc -g -c shell.c
myStr.o:myStr.c
	gcc -g -c myStr.c
clean:
	rm shell.o shell