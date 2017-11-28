//
// Created by Adam Kruschwitz on 11/13/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_ARRAYMAP_INL
#define RANDOMBOOKNAMEGENERATOR_ARRAYMAP_INL
#include "ArrayMap.h"
#include <iostream>

template <class K, class V>
ArrayMap<K, V>::ArrayMap(){
    capacity = 5;
    mapSize = 0;
    keysArray = new K[capacity];
    valuesArray = new V[capacity];
}

template <class K, class V>
ArrayMap<K, V>::~ArrayMap(){
    delete[] keysArray;
    delete[] valuesArray;
}

template <class K, class V>
void ArrayMap<K, V>::doubleArrayCapacity(){
    capacity *= 2;
    K* newKeysArray = new K[capacity];
    V* newValuesArray = new V[capacity];

    for(int i = 0; i < mapSize; i++) {
        newKeysArray[i] = keysArray[i];
        newValuesArray[i] = valuesArray[i];
    }

    delete[] keysArray;
    delete[] valuesArray;
    keysArray = newKeysArray;
    valuesArray = newValuesArray;
};

template <class K, class V>
void ArrayMap<K, V>::put(K key, V value) {
    if(mapSize>=capacity){
        doubleArrayCapacity();
    }

    keysArray[mapSize] = key;
    valuesArray[mapSize] = value;
    mapSize++;
}

template <class K, class V>
V ArrayMap<K, V>::get(K key) {
    bool found = false;
    int foundIndex = 0;
    for(foundIndex; foundIndex < mapSize && !found; foundIndex++) {
        if(keysArray[foundIndex]==key) {
            found = true;
        }
    }
    if(!found) {
        throw std::out_of_range("Key not found");
    } else {
        return valuesArray[foundIndex];
    }
}

template <class K, class V>
K* ArrayMap<K, V>::keys() {
    K* out = new K[mapSize];
    for(int i; i<mapSize; i++) {
        out[i] = keysArray[i];
    }
    return out;
}

template <class K, class V>
V* ArrayMap<K, V>::values() {
    V* out = new K[mapSize];
    for(int i; i<mapSize; i++) {
        out[i] = valuesArray[i];
    }
    return out;
}

#endif //RANDOMBOOKNAMEGENERATOR_MAP_INL