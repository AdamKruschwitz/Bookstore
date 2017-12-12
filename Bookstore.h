//
// Created by Adam Kruschwitz on 12/1/17.
//

#ifndef BOOKSTORE_2_ELECTRIC_BOOGALOO_BOOKSTORE_H
#define BOOKSTORE_2_ELECTRIC_BOOGALOO_BOOKSTORE_H

//#include "ArrayList.h"
#include "Book.h"
#include "Person.h"
#include <string>
#include "BookList.h"

class Bookstore {
private:
    BookList* bookList = nullptr;

public:
    /**
     * A default constructor, creates the booklist and runs load library
     */
    Bookstore();

    /**
     * A destructor, runs load library and destroys the bookList
     */
    ~Bookstore();

    /**
     * Add's a book to the bookList
     * @param newTitle title of the book to be added
     * @post a new book object is created of the given title,
     */
    Book* addBook(std::string newTitle);
    int getLibrarySize();
    Book* getBookAt(int index);
};
#endif //BOOKSTORE_2_ELECTRIC_BOOGALOO_BOOKSTORE_H
