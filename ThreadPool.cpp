//
// Created by Maurizio on 03/12/16.
//

#include "ThreadPool.h"


ThreadPool::ThreadPool(int numThread){
    this->numThread = numThread;
}

void ThreadPool::setQueue(Queue<Work> *queue) {
    this->queue = queue;
}

void ThreadPool::managePool(int i) {
    while(!queue->isEmpty()) {
        mtx.lock();
        Work w = *(queue->dequeue());
        mtx.unlock();
        printf("Thread %d run work %d\n",i,w.getId());
        w.doWork();
    }
}

void ThreadPool::threadPool() {
    int i = 0;
    printf("Totale Work nella queue = %d\n" , queue->size());
    clock_t start = clock();
    for (int i = 0; i < this->numThread; ++i)
        some_threads.push_back(std::thread(&ThreadPool::managePool,this, i));

    clock_t end = clock();
    for (auto& t: some_threads) t.join();
    double diffticks = end - start;
    double diffms = diffticks / ( CLOCKS_PER_SEC / 1000 );
    printf("Totale Work nella queue %d\n" , queue->size());
    printf("Tempo totale per la generezione dei Thread %lf ms\n" , diffms);

}