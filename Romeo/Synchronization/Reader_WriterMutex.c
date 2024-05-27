
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t wr,mutex;
int a=10;
int readcount=0;

void * reader(void * arg){
 long int num;
 num=(long int)arg;

 pthread_mutex_lock(&mutex);//Reader entering in CS
 readcount++;
 pthread_mutex_unlock(&mutex);

 if(readcount==1)
 pthread_mutex_lock(&wr);

 printf("\n Reader %ld is reading a data %d",num,a);
 sleep(1);
 pthread_mutex_lock(&mutex);//Reader leaving in CS
 readcount--;
 pthread_mutex_unlock(&mutex);

 if(readcount==0)
 pthread_mutex_unlock(&wr);
  
}

void * writer(void * arg){
 long int num;
 num=(long int)arg;

 pthread_mutex_lock(&wr);//writer entering in CS
 
 printf("\n Writer %ld is Writing a data %d",num,++a);
 sleep(1);
 pthread_mutex_unlock(&wr);// writer leaving CS

    
}
int main(){
    pthread_t r[10], w[10];
    int nor,now;
    int long i,j;

    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_init(&wr,NULL);

    printf(" Enter No. of Reader and Writer:  ");
    scanf("%d %d",&nor, &now);

    for(i=0;i<nor;i++){
        pthread_create(&r[i],NULL,reader,(void *)i);
    }

    for(j=0;j<now;j++){
        pthread_create(&w[j],NULL,writer,(void *)j);

    }

    for(int i=0;i<nor;i++){
        pthread_join(r[i],NULL);
    }

    for(j=0;j<now;j++){
        pthread_join(w[j],NULL);
    }
}