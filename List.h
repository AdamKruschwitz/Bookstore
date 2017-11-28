//
// Created by Adam Kruschwitz on 11/10/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_LIST_H
#define RANDOMBOOKNAMEGENERATOR_LIST_H
#include <string>

template <class T>
class List {

public:
    int size;
    virtual ~List(){};

    virtual void insertAtFront(T item)=0;
    virtual void insertAtEnd(T item)=0;
    virtual void insertAt(T item, int index)=0;

    virtual T getValueAt(int index)=0;
    virtual T removeValueAt(int index)=0;
    virtual bool isEmpty()=0;
    virtual std::string toString()=0;
    virtual int find(T item)=0;
    virtual int findLast(T item)=0;
};

#endif //RANDOMBOOKNAMEGENERATOR_LIST_H
