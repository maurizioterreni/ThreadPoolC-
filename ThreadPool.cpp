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
        std::thread t;
        printf("Thread %d run work %d\n",i,w.getId());
        t = std::thread(w);
        t.join();
    }
}

void ThreadPool::threadPool() {
    int i = 0;
    printf("Totale Work nella queue = %d\n" , queue->size());
    for (int i = 0; i < this->numThread; ++i)
        some_threads.push_back(std::thread(&ThreadPool::managePool,this, i));
    for (auto& t: some_threads) t.join();
    printf("Totale Work nella queue %d\n" , queue->size());
}