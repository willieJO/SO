#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    char *args[]={"ls", NULL};
    pid= fork(); // chamada ao sistema replicando o sistema pai
    if(pid!=0){
        printf("AAAAA, %d",pid);
    }else{
        printf("bbbbbbb, %d",pid);
        if(execvp("ls",args)==-1){
            printf("erro");
        }else{
            printf("ok");
        }
    }
    //$ gcc aula.c -o aulaTeste
    pause();
    return 1;
}