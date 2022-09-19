#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char*argv[]){
    pid_t pid;
    pid = fork(); // chamada ao sistema replicando o sistema pai
    if(pid!=0){
        pri("AAAAA, %d",pid);
    }else{
        printf("bbbbbbb, %d",pid);
        if(execvp(argv[1],argv)==-1){
            printf("erro");
        }
    }
    //$ gcc aula.c -o aulaTeste
    pause();
    return 1;
}