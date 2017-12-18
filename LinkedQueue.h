//
// Created by Toby Dragon on 10/22/17.
//

#ifndef STACKSANDQUEUES_LINKED_QUEUE_H
#define STACKSANDQUEUES_LINKED_QUEUE_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"
#include "Queue.h"


/**
 * Represents a FIFO data structure (First In First Out). Picture a line
 * to wait for something (first person in is the first person out)
 */

template <class T>
class LinkedQueue : public Queue<T> {
private:
    LinkedNode<T>* front;
    LinkedNode<T>* end;
    int size;

public:
    
    //Creates an empty queue
    LinkedQueue<T>();

    //Copy Constructor
    LinkedQueue(const LinkedQueue& queueToCopy);

    //Destructor
    ~LinkedQueue();
    
    //adds an item to the end of the queue
    void enqueue(T& item);

    //takes an item off the front of the queue and returns it
    //throws out_of_range exception if the queue is empty
    T dequeue();

    //returns true if the queue has no items, false otherwise
    bool isEmpty();

    //returns size
    int getSize();

};

#include "LinkedQueue.inl"

#endif //STACKSANDQUEUES_LINKED_QUEUE_H
