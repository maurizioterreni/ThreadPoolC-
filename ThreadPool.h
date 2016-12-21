//
// Created by Maurizio on 03/12/16.
//

#ifndef TEST_THREADPOOL_H
#define TEST_THREADPOOL_H


#include <mutex>
#include <thread>
#include <vector>
#include <stdio.h> // printf
#include "queue.h"
#include "Work.h"

class ThreadPool {
private:
    Queue<Work> *queue;
    std::mutex mtx;
    int numThread;
    std::vector<std::thread> some_threads;
public:
    ThreadPool(int numThread);
    void setQueue(Queue<Work> *queue);


    void managePool(int i);
    void threadPool();
};


#endif //TEST_THREADPOOL_H
