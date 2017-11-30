//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
template <class T>
LinkedQueue<T>::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
template <class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& queueToCopy){
    if (queueToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
    }
    else {
        LinkedNode<T>* nodeToCopy = queueToCopy.front;
        front = new LinkedNode<T>(nodeToCopy->getItem());
        LinkedNode<T>* endOfNewChain = front;

        nodeToCopy = nodeToCopy->getNext();
        while (nodeToCopy != nullptr){
            LinkedNode<T>* newNode = new LinkedNode<T>(nodeToCopy->getItem());
            endOfNewChain->setNext(newNode);
            endOfNewChain = newNode;
            nodeToCopy = nodeToCopy->getNext();
        }
        end = endOfNewChain;
    }
}

//Destructor
template <class T>
LinkedQueue<T>::~LinkedQueue(){
    while (front != nullptr){
        LinkedNode<T>* toDelete = end;
        front = front->getNext();
        delete toDelete;
    }
}


//adds an item to the end of the queue
template <class T>
void LinkedQueue<T>::enqueue(T item){
    LinkedNode<T>* newNode = new LinkedNode<T>(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
template <class T>
T LinkedQueue<T>::dequeue(){
    if (isEmpty()){
        throw std::out_of_range("Can't dequeue from empty queue");
    }
    else {
        T item = front->getItem();
        if (front == end) {
            delete front;
            front = nullptr;
            end = nullptr;
        } else {
            LinkedNode<T>* toDelete = front;
            front = front->getNext();
            delete toDelete;
        }
        return item;
    }
}

//returns true if the queue has no items, false otherwise
template <class T>
bool LinkedQueue<T>::isEmpty(){
    return front == nullptr;
}