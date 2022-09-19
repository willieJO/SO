#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// integrantes: ARTHUR JOSÉ REGIANI e Willie Joaber De OLiveira
void mostrarTela(char input[])
{
    int validar=0;
       
    while(validar==0){
        printf("<3 ");
        gets(input);
        if(strlen(input)>0){
            validar=1;
        }
        
    }
    
}
int main(int argc, char *argv[])
{
    //int x = 1;
    while (1)
    {
        char input[131072];
        mostrarTela(input);
        char s[131072];
        strcpy(s, input);
        char *argumento[131072];
        char *token = strtok(s, " ");
        int i = 0;
        int flagCd=0;
        while (token)
        {            
            argumento[i] = token;
            token = strtok(NULL, " ");
            i++;
        }

        argumento[i] = NULL;
                
        if(strcmp(argumento[0],"cd")==0){
            chdir(argumento[i-1]);         
        } else {
            pid_t pid = fork(); 
            if (pid == -1) {
                //erro na criação
            
            } else if (pid == 0) {
                if (execvp(argumento[0], argumento) < 0) {
                    printf("Não foi possivel execultar o comando\n");
                    
            }
            
            
            } else {
                
                
            }
        }
        
    }
    return 1;
}
