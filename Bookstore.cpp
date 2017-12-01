//
// Created by Adam Kruschwitz on 12/1/17.
//

#include "Bookstore.h"

Bookstore::Bookstore() {
    if(bookList==nullptr) {
        bookList = new ArrayList<Book>();
    }
    loadLibrary();
}

Bookstore::~Bookstore() {
    saveLibrary();
    bookList->~ArrayList();
    bookList = nullptr;
}