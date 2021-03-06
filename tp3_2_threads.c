#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define THREADS 300

sem_t okToBuy;
int ticketsAvailable;
int ok_index;
int fail_index;
pthread_t exitosos[THREADS];
pthread_t fallidos[THREADS];

void* getTicket(void *arg){

  pthread_t self_id;
  self_id=pthread_self();

  int marcado = 0;

  while( ticketsAvailable > 0 ){
    sem_wait(&okToBuy);
    if (marcado==0){
      exitosos[ok_index] = self_id;
      ok_index++;
      marcado = 1;
    }
    --ticketsAvailable;
    sem_post(&okToBuy);
    sleep(1);
  }

  if (marcado!=0){


    sem_wait(&okToBuy);

    fallidos[fail_index]= self_id;
    fail_index++;
    sem_post(&okToBuy);


  }





    return NULL;


}


int main(int argc, char **argv)
{
  pthread_t '0'[THREADS];
  ticketsAvailable = 200;
  ok_index = 0;
  fail_index = 0;

  // Init semaphore
  if(sem_init(&okToBuy, 0, 1)){
    printf("Could not initialize a semaphore\n");
    return -1;
  }

  // Creates the threads
  for(int i = 0; i < THREADS; ++i){
    if(pthread_create(&threads[i], NULL, &getTicket, NULL)){
      printf("Could not create thread %d\n", i);
      return -1;
    }
  }


    //espera que terminen los threads
    for(int i = 0; i < THREADS; ++i)
    {
      //espera que termine el thread i
        if(pthread_join(threads[i], NULL))
        {
            printf("Could not join thread %d\n", i);
            return -1;
        }
    }

    printf("\n\nThreads que compraron\n");

    // Creates the threads
    for(int i = 0; i < THREADS; ++i){

      if (exitosos[i]!=0)
        printf("   %d\n", exitosos[i]);
    }
    printf("\n\nThreads que NO compraron\n");

    // Creates the threads
    for(int i = 0; i < THREADS; ++i){

      if (fallidos[i]!=0)
        printf("   %d\n", fallidos[i]);
    }

    sem_destroy(&okToBuy);


    return 0;
}
