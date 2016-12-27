//
// Created by Maurizio on 03/12/16.
//

#include "Work.h"


Work::Work(int id, int s) {
    this->id = id;
    this->s = s;
}

int Work::getId() {
    return this->id;
}
void Work::doWork() {
    printf("######  work %i start with duration %d\n", this->id,this->s);
    sleep(s);
    printf("######  work %i end \n", this->id);
}