#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "myStr.h"

#define MAX_ARGS 10
#define MAX_PATH_LENGTH 256

int main(int argc,char** argv){
    printf("start running!\n");

    char** targv = (char**)malloc(MAX_ARGS* sizeof(char*));
    memset(targv,0,sizeof(targv));
    char* chs = NULL;

    while(1){
        size_t ch_nums = 0;
        
        printf("$");
        getline(&chs, &ch_nums, stdin);
        //printf("%s",chs);
        if(strcmp(chs,"exit\n") == 0){
            break;
        }
        else if(strcmp(chs,"\n") == 0){
            continue;
        }
        chs[strlen(chs)-1] = '\0';
        char* fullCommandCopy = copyStr(chs);


        //parse ' ' first, notice that targv[0] might be a path
        char *childStr = strtok(chs," ");
        //char* file = copyStr(childStr);
        int argCount = 0;
        //split string
        while(childStr != NULL){
            if(argCount >= MAX_ARGS){
                printf("error: The max args num exceeded,\
                 max args number is %d.\n", MAX_ARGS);
                break;
            }
            targv[argCount] = childStr;
            argCount++;
            childStr = strtok(NULL," ");
        }

        //parse the path
        //check whether the file using absolute path
        char* tmpfile = copyStr(targv[0]);
        char* file = copyStr(targv[0]);
        if (strstr(tmpfile, "/") == NULL){
            
            //do nothing
        }
        else{
            char* tmpCh = strtok(tmpfile,"/");
            char* nextCh;
            while(1){
                nextCh = strtok(NULL,"/");
                if(nextCh == NULL){
                    targv[0] = tmpCh;
                    break;
                }
                else{
                    tmpCh = nextCh;
                }
            }
            
        }

        //cd 
        if(strcmp(file,"cd")== 0){
            if (argCount == 1 || argCount > 2){
                printf("error:cd args num invalid\n");
            }
            char path[MAX_PATH_LENGTH];
            getcwd(path, MAX_PATH_LENGTH);
            printf("path before:%s\n", path);
            chdir(targv[1]);
            getcwd(path, MAX_PATH_LENGTH);
            printf("path after:%s\n", path);
        }
        else{
            __pid_t pid = fork();
            if(pid == -1){
                perror("failed to fork");
                return 1;
            }
            else if (pid == 0)
            {      
                //printf("a\n");
                int res = execvp(file,targv);
                
                printf("Child failed to exec the command,error:%s\n",strerror(errno));
                return 1;
            }
            else{
                waitpid(pid, NULL, 0 );
            }
        }

        //end,clear the targv and free memory
        int tmpArgCount = 0;
        while(targv[tmpArgCount] != NULL){
            //free(targv[tmpArgCount]);
            targv[tmpArgCount] = NULL;
            tmpArgCount++;
        }

        free(file);
        free(tmpfile);
    }
    //free targv and chs
    int tmpArgCount = 0;
    while(targv[tmpArgCount] != NULL){
        //free(targv[tmpArgCount]);
        tmpArgCount++;
    }
    free(targv);
    free(chs);

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

