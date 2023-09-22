#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

int main(int argc,char** argv){
    printf("start running!\n");

    char* targv[] = malloc(MAX_ARGS* sizeof(char*));
    while(1){
        size_t ch_nums = 0;
        char* chs = NULL;
        printf("$");
        getline(&chs, &ch_nums, stdin);
        printf("%s",chs);
        if(strcmp(chs,"exit\n") == 0){
            free(chs);
            break;
        }

        //split string



        free(chs);
    }
    //char* targv[] = {"ls", "-l", NULL};
    // char* targv[] = {"ls", NULL};

    // __pid_t pid = fork();
    // if(pid == -1){
    //     perror("failed to fork");
    //     return 1;
    // }
    // else if (pid == 0)
    // {   
    //     printf("a\n");
    //     int res = execvp("ls",targv);

    //     perror("Child failed to exec ls");
	// 	return 1;
    // }
    // else{
    //     waitpid( pid, NULL, 0 );
    //     printf("b\n");
	// 	// 父进程代码
	// 	perror("Parent failed to wait due to signal or error");
	// 	return 1;
    // }
    
    return 0;

}