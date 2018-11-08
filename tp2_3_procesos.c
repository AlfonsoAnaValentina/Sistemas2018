#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

#define THREADS 20

sem_t OKToBuyMilk;
int milkAvailable;

void* buyer(void *arg)
{
    // P()
    sem_wait(&OKToBuyMilk);
    if(!milkAvailable)
    {
        // compra la leche, la incrementa
        ++milkAvailable;
    }
    // V()
    sem_post(&OKToBuyMilk);

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t threads[THREADS];

    milkAvailable = 0;

    // Inicializa el thread en la direccion del primer parametro &OKToBuyMilk
    // con el valor del tercer parametro 1
    // el 0 del segundo parametro indica que va a ser compartido entre threads
    if(sem_init(&OKToBuyMilk, 0, 1))
    {
        printf("Could not initialize a semaphore\n");
        return -1;
    }

    for(int i = 0; i < THREADS; ++i)
    {
      //crea el thread del proceso buyer
        //si no puede crear el thread imprime por consola el mensaje
        if(pthread_create(&threads[i], NULL, &buyer, NULL))
        {
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
    //destruye los semaforos en la direccion indicada por la variable ok to buy milk
    sem_destroy(&OKToBuyMilk);

    // se asegura que no tengamos mucha miel disponible
    printf("Total milk: %d\n", milkAvailable);

    return 0;
}
