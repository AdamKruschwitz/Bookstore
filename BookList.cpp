//
// Created by Adam Kruschwitz on 12/8/17.
//

#include "BookList.h"

BookList::BookList() {
    booksCapacity = 5;
    bookNumber = 0;
    books = new Book*[booksCapacity];
    //loadList();
}

BookList::~BookList() {
    //saveList();
    delete[] books;
    books = nullptr;
}

void BookList::doubleCapactiy() {
    booksCapacity *= 2;
    Book** newBooks = new Book*[booksCapacity];
    for (int i = 0; i < bookNumber; i++) {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;
}

Book* BookList::insertBook(std::string bookTitle) {
    Book* bookToAdd = new Book(bookTitle);
    if(getBook(bookTitle) != nullptr) {
        return nullptr;
    }

    if(bookNumber >= booksCapacity) {
        doubleCapactiy();
    }
    int indexToInsert = bookNumber;
    for(int i = 0; i < bookNumber && indexToInsert == bookNumber; i++) {
        if(bookToAdd < books[i]) {
            indexToInsert = i;
        }
    }
    for(int i = bookNumber; i > indexToInsert; i--) {
        books[i] = books[i-1];
    }
    books[indexToInsert] = bookToAdd;
    return bookToAdd;
}


Book* findBook(Book* bookToCompare, Book** array, int size) {
    int mid = size/2;
    if(size <= 0) {
        return nullptr;
    }
    else if ((&array[mid]) == &bookToCompare) {
        return array[mid];
    }
    else if (&array[mid] < &bookToCompare) {
        return findBook(bookToCompare, array+mid, size-mid);
    }
    else {
        return findBook(bookToCompare, array, size-mid);
    }
}

Book* BookList::getBook(std::string bookTitle) {
    Book* bookToCompare = new Book(bookTitle);
    return findBook(bookToCompare, books, bookNumber);
}

