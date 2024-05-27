#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#include<stdlib.h>


#define N 10

int buffer[N];
typedef int semaphore;
semaphore mutex=1;
semaphore empty=N;
semaphore full=0;
int in=0;
int out=0;

void wait(semaphore *s){
    while(*s <=0);
    (*s)--;
}

void signal(semaphore *s){
    (*s)++;
}

void *producer(void* arg){
 int item;

 while(true){
    item=rand()%100;
    wait(&mutex);
    wait(&empty);
    buffer[in]=item;
    printf("Producer produced item : %d\n",item);
    in=(in+1)%N;
    signal(&mutex);
    signal(&full);
    sleep(1);
     }
}

void *consumer(void* arg){
 int item;
 while(true){
    wait(&mutex);
    wait(&full);
    item=buffer[out];
    printf("Consumer consumer item : %d\n",item);
    out=(out+1)%N;
    signal(&mutex);
    signal(&empty);
    sleep(2);
 }
}

int main(){
    pthread_t producer_thread,consumer_thread;

    pthread_create(&producer_thread,NULL,producer,NULL);
    pthread_create(&consumer_thread,NULL,consumer,NULL);

    pthread_join(producer_thread,NULL);
    pthread_join(consumer_thread,NULL);

    return 0;

}
