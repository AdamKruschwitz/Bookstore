//
// Created by Adam Kruschwitz on 11/10/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_ARRAYLIST_H
#define RANDOMBOOKNAMEGENERATOR_ARRAYLIST_H
#include <iostream>
#include "List.h"
#include <string>

template <class T>
class ArrayList : public List {
private:
    int capacity;
    int ListSize;
    T* array;

public:
    ArrayList();
    ArrayList(const ArrayList arrayListToCopy);
    ~ArrayList();

    void insertAtFront(T item);
    void insertAtEnd(T item);
    void insertAt(T item, int index);
    T removeValueAt(int index);

    bool isEmpty();
    T getValueAt(int index);
    int find(T item);
    int findLast(T item);
    std::string toString();
};
#endif //RANDOMBOOKNAMEGENERATOR_ARRAYLIST_H
