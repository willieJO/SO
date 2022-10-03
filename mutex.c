#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
int comp; // reguçai crutuca pe i orubt e o comp que são lugares que compartilham o recurso
pthread_mutex_t mutex;
void *printHello(void *thread_id){
    int i=0;
    long t_id; 
    t_id = (long) thread_id;
    for(i=0;i<5;i++){
        pthread_mutex_lock(&mutex);
        printf("Thead function %d %ld\n",i,t_id);
        comp++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);

}

int main(){
    printf("THead principal (Main)\n");
    pthread_t thead;
    int i=0;
    long param=0;
    comp =0;
    int rc = pthread_create(&thead,NULL,printHello,(void *)param);
    param=1;
    int rc2 = pthread_create(&thead,NULL,printHello,(void *)param);
    for(i=0;i<5;i++){
        pthread_mutex_lock(&mutex);
        printf("Thead for %d %d\n",i,comp);
        comp++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    if(rc){ //1
       printf("erro");
       exit(-1);
    }
    
     if(rc2){ //1
       printf("erro");
       exit(-1);
    }
   
    pthread_exit(NULL);
}

