//
// Created by Maurizio on 03/12/16.
//

#ifndef PTHREADS_CPP_THREAD_H
#define PTHREADS_CPP_THREAD_H

#include <pthread.h>
#include <cstdio>
#include <unistd.h> // sleep

class Work {
private:
    int id;
    int s;
public:
    Work(int i,int s);
    int getId();
    void doWork();
};


#endif //PTHREADS_CPP_THREAD_H
