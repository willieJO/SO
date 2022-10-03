#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


// -1 nada produzido
// Posição 0 se tem algo produzido ou não  0 nada produzido 1 produziu algo 
// se preocupar com vetor vazio e vetor cheioo 
int produtores[10];
int consumidores; //quantidade que for devinida  nos args
//numero de produtores numero de consumidores 
// quando for -1 não tem o produto 
// [-1,1,2-1,7]

int main (int argc, char *argv[ ]){
    srand(time(NULL));
    
    printf("%d\n", rand() % 10);
}