//
// Created by Adam Kruschwitz on 11/14/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_BOOK_H
#define RANDOMBOOKNAMEGENERATOR_BOOK_H
#include <string>
#include "Queue.h"
#include "LinkedQueue.h"
#include "Person.h"

class Book {

private:
    int have;
    int want;
    LinkedQueue<Person> waitingList;
    double price;
    std::string title;

public:
    Book();
    Book(std::string title);
    Book(Book& bookToCopy);
    bool operator==(const Book other);
    bool operator<(const Book other);
    bool operator>(const Book other);
    ~Book();
    int getHave();
    int getWant();
    double getPrice();
    std::string getTitle();
    void setHave(int newHave);
    void setWant(int newWant);
    void setPrice(double newPrice);
    void setTitle(std::string newTitle);
    void addToWaitingList(Person newPerson);
    void removeFromWaitingList();
    int calculateRestock();
    Queue<Person> getWaitingList();
    void restock(int numNewCopies);
};

#endif //RANDOMBOOKNAMEGENERATOR_BOOK_H
