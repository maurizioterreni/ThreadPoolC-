#include <stdlib.h>
#include <time.h>

#include "Work.h"
#include "queue.h"
#include "ThreadPool.h"

#define NUM_MAX_TRHEAD 20
#define NUM_THREAD_POOL 4



int main(int argc, char** argv)
{

    printf("Tread Pool Terreni Maurizio Parallel Computing 2016-2017\n");
    printf("Numero di work eseguiti contemporaneamente %d\nNumero di work nella queue %d\n\n\n",NUM_THREAD_POOL,NUM_MAX_TRHEAD);

    sleep(2);

    Queue<Work> *queueWork = new Queue<Work>();
    Queue<Work> *queue2 = new Queue<Work>();

    srand (time(NULL));
    for(int i=0; i<NUM_MAX_TRHEAD; i++){
        Work *work = new Work(i + 1,(rand() % 15) + 2);
        queueWork->enqueue(work);
        queue2->enqueue(work);
    }



    ThreadPool *threadPool = new ThreadPool(NUM_THREAD_POOL);

    threadPool->setQueue(queueWork);

    threadPool->threadPool();
    printf("Totale Work nella queue = %d\n" , queue2->size());
    clock_t start = clock();
    std::vector<std::thread> some_threads;
    while(!queue2->isEmpty()){
        Work *w = queue2->dequeue();
        //printf("dequeue %d\n",queue2->size());
        some_threads.push_back(std::thread(&Work::doWork,w));
    }

    clock_t end = clock();

    for (auto& t: some_threads) t.join();
    double diffticks = end - start;
    double diffms = diffticks / ( CLOCKS_PER_SEC / 1000 );
    printf("Totale Work nella queue = %d\n" , queue2->size());
    printf("Tempo totale per la generezione dei Thread %lf ms\n" , diffms);
    printf("main done\n");
    exit(0);
}
