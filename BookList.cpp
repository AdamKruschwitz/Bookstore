//
// Created by Adam Kruschwitz on 12/8/17.
//

#include "BookList.h"
#include "Bookstore.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
BookList::BookList() {
    booksCapacity = 5;
    bookNumber = 0;
    books = new Book*[booksCapacity];
    loadList();
}


BookList::~BookList() {
    saveList();
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
int BookList::getSize(){
    return bookNumber;
}

Book* BookList::getValueAt(int location){
    return books[location];
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
    bookNumber++;
    return bookToAdd;
}


Book* findBook(Book* bookToCompare, Book** array, int size) {
    int mid = size/2;
    if(size <= 0) {
        return nullptr;
    }
    else if ((*array[mid]) == *bookToCompare) {
        return array[mid];
    }
    else if (*array[mid] < *bookToCompare) {
        return findBook(bookToCompare, array+mid, size-mid);
    }
    else {
        return findBook(bookToCompare, array, size-mid);
    }
}

Book* BookList::getBook(std::string bookTitle) {
    Book* bookToCompare = new Book(bookTitle);
    for(int i=0; i < bookNumber; i++) {
        if(*bookToCompare == *books[i]) {
            delete bookToCompare;
            return books[i];
        }
    }
    delete bookToCompare;
    return nullptr;
}

void BookList::saveList() {
    std::ofstream fout ("inventory.txt");
    std::string output="";
    std::string title = "";
    std::string want = "";
    std::string have = "";
    std::string price = "";
    if (fout) {
        for (int i = 0; i < bookNumber; ++i) {
            Book *current = (books[i]);
            title = current->getTitle();
            want = std::to_string(current->getWant());
            have = std::to_string(current->getHave());
            price = std::to_string(current->getPrice());
            output += title + "," + want + "," + have + "," + price+",";
            LinkedQueue<Person> waitingList = current->getWaitingList();
            while (!waitingList.isEmpty()){

                            //LinkedQueue<Person> out = current->getWaitingList();
                            Person guy = waitingList.dequeue();
                            std::string name = guy.getName() + ",";
                            std::string email = guy.getEmail() + ",";
                            std::string number = guy.getNumber()+ ",";
                            std::string pref = guy.getPreference()+ ",";

                output+= name + email + number + pref;
            }
            output += "\n";
        }
        fout << output;
    } else{
        std::cout << "error in opening inventory.txt" << std::endl;
    }
}

void createBookFromString(BookList& thisBookList, std::string data){
    if(data!="") {

        //gets a string from file
        std::stringstream parts(data);
        std::string part;

        //parses the first part for the title and creates a book with it
        getline(parts, part, ',');
        Book *bookToAdd = thisBookList.insertBook(part);

        //parses again to get want value
        getline(parts, part, ',');
        int want = stoi(part);
        bookToAdd->setWant(want);

        //parses again to get have value
        getline(parts, part, ',');
        int have = stoi(part);
        bookToAdd->setHave(have);

        //parses again to get the price
        getline(parts, part, ',');
        double price = stod(part);
        bookToAdd->setPrice(price);

        //getline(parts,part, ',');
        if (parts){ //add new specific delim

            getline(parts, part, ',');
            std::string name = part;

            getline(parts, part, ',');
            std::string email = part;

            getline(parts, part, ',');
            std::string number = part;

            getline(parts, part, ',');
            std::string pref = part;

            Person* toAdd = new Person();

            toAdd->setName(name);
            toAdd->setEmail(email);
            toAdd->setNumber(number);
            toAdd->setPreference(pref);

            bookToAdd->addToWaitingList(*toAdd);
       }

    }
}

void BookList::loadList() {

    std::ifstream fin ("inventory.txt");

    if (fin){
        while(fin) {
            std::string str = "";
            getline(fin, str);
            createBookFromString(*this, str);
        }
    }
}
