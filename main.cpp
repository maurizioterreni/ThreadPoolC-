#include <stdlib.h>
#include <time.h>

#include "Work.h"
#include "queue.h"
#include "ThreadPool.h"

#define NUM_MAX_TRHEAD 15
#define NUM_THREAD_POOL 4



int main(int argc, char** argv)
{

    printf("Tread Pool Terreni Maurizio Parallel Computing 2016-2017\n");
    printf("Numero di work eseguiti contemporaneamente 4\nNumero di work nella queue 15\n\n\n");

    sleep(2);

    Queue<Work> *queueWork = new Queue<Work>();

    srand (time(NULL));
    for(int i=0; i<NUM_MAX_TRHEAD; i++){
        Work *work = new Work(i + 1,(rand() % 15) + 2);
        queueWork->enqueue(work);
    }



    ThreadPool *threadPool = new ThreadPool(NUM_THREAD_POOL);

    threadPool->setQueue(queueWork);

    threadPool->threadPool();

    printf("main done\n");
    exit(0);
}
