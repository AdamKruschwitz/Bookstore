//
// Created by Adam Kruschwitz on 11/13/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_ARRAYMAP_H
#define RANDOMBOOKNAMEGENERATOR_ARRAYMAP_H
#include "Map.h"

template <class K, class V>

class ArrayMap : public Map {
private:
    int capacity;
    int mapSize;
    K* keysArray;
    V* valuesArray;
    void doubleArrayCapacity();

public:
    ArrayMap();
    ~ArrayMap();
    void put(K key, V value);
    V get(K key);
    K* keys();
    V* values();
};
#endif //RANDOMBOOKNAMEGENERATOR_ARRAYMAP_H
