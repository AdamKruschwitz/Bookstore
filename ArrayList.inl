//
// Created by Adam Kruschwitz on 11/13/17.
//

#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList() {
    capacity = 5;
    array = new T[capacity];
    ListSize = 0;
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy) {
    delete array;
    array = new T[arrayListToCopy.capacity];
    ListSize = arrayListToCopy.ListSize;
    for(int i=0; i<ListSize; i++) {
        array[i] = arrayListToCopy.array[i];
    }
}

template <class T>
ArrayList<T>::~ArrayList() {
    delete array;
}

template <class T>
void ArrayList<T>::doubleCapacity() {
    capacity *= 2;
    T* newArray = new T[capacity];
    for(int i=0; i<ListSize; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
}

template <class T>
void ArrayList<T>::insertAtFront(T item) {
    if(ListSize >= capacity) {
        doubleCapacity();
    }
    for(int i = ListSize; i > 0; i--) {
        array[i] = array[i-1];
    }
    array[0] = item;

}