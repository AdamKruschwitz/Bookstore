//
// Created by Adam Kruschwitz on 11/13/17.
//


#ifndef RANDOMBOOKNAMEGENERATOR_MAP_H
#define RANDOMBOOKNAMEGENERATOR_MAP_H

template <class K, class V>

class Map {
public:
    virtual void put(K key, V value)=0;
    virtual V get(K key)=0;
    virtual K* keys()=0;
    virtual V* values()=0;
};

#endif //RANDOMBOOKNAMEGENERATOR_MAP_H
