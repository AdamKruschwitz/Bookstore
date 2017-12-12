//
// Created by Adam Kruschwitz on 12/1/17.
//

#include "Bookstore.h"

Bookstore::Bookstore() {
    if(bookList==nullptr) {
        bookList = new BookList();
    }
    loadLibrary();
}

Bookstore::~Bookstore() {
    saveLibrary();
    bookList->~BookList();
    bookList = nullptr;
}

Book* Bookstore::addBook(std::string newTitle) {
    //Book* newBook = new Book(newTitle);
    return bookList->insertBook(newTitle);
}

int Bookstore::getLibrarySize() {
    return bookList->getSize();
}

Book* Bookstore::getBookAt(int index) {
    return bookList->getValueAt(index);
}

Book* Bookstore::findBook(std::string title) {
    return bookList->getBook(title);
}