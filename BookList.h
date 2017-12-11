//
// Created by Adam Kruschwitz on 12/8/17.
//

#ifndef BOOKSTORE_BOOKLIST_H
#define BOOKSTORE_BOOKLIST_H

#include <iostream>
#include "Book.h"
#include <string>

class BookList {
private:
    Book** books;
    int bookNumber;
    int booksCapacity;
    void doubleCapactiy();

public:
    BookList();
    ~BookList();
    Book* insertBook(std::string bookTitle);
    Book* getBook(std::string bookTitle);
    //void loadList();
    //void saveList();
};


#endif //BOOKSTORE_BOOKLIST_H
