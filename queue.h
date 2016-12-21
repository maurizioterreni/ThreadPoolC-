//
// Created by Maurizio on 03/12/16.
//

#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H


#include <cstdlib>

template <class T> class Node
{
public:
    T *data;
    Node* next;
};

template <class T> class Queue {
private :
    Node<T>* front;
    Node<T>* rear;
    int count;


public:
    Queue(){
        this->front = NULL;
        this->rear = NULL;
        this->count = 0;
    }
    int size(){
        return count;
    }

    void enqueue(T *obj){
        Node<T>* tmp = new Node<T>();
        tmp->data = obj;
        tmp->next = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = rear = tmp;
        }
        else {
            // Append to the list
            rear->next = tmp;
            rear = tmp;
        }

        count++;
    }
    T * dequeue(){
        if ( isEmpty() )
            return NULL;

        T *risu = front->data;
        Node<T>* tmp = front;

        // Move the front pointer to next node
        front = front->next;

        count--;
        delete tmp;
        return risu;
    }
    bool isEmpty(){
        return count == 0 ? true : false;
    }

};



#endif //TEST_QUEUE_H
