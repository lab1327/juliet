#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>

#define N 10

typedef int semaphore;
semaphore mutex=1;
semaphore db=1;
int rc=0;

void wait(semaphore *s){
    while(*s<=0);
    (*s)--;
}

void signal(semaphore *s){
    (*s)++;
}

void readbuffer(){
    printf("Reading fom buffer \n");
}

void *reader(void* arg){
    while(true){
        wait(&mutex);
        rc=rc+1;
        if(rc==1){
            wait(&db);
        }
        signal(&mutex); 

        readbuffer();
       
        wait(&mutex);
      rc=rc-1;
      if(rc==0){
        signal(&db);
      }
      signal(&mutex);
      sleep(1);
    }

}

void writebuffer(){
    printf("Writing to Buffer\n");
}

void *writer(void *arg){
    while(true){

        wait(&db);
        writebuffer();
        signal(&db);
        sleep(2);
    }
}

int main(){
    pthread_t reader_thread,writer_thread;

    pthread_create(&reader_thread,NULL,reader,NULL);
    pthread_create(&writer_thread,NULL,writer,NULL);

    pthread_join(reader_thread,NULL);
    pthread_join(writer_thread,NULL);
}