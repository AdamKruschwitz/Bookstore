//
// Created by Adam Kruschwitz on 11/14/17.
//

#include "Book.h"

Book::Book() {
    have = 0;
    want = 0;
    price = 0.0;
    title = "NONAME";
}

Book::Book(std::string title) {
    this->title = title;
    have = 0;
    want = 0;
    price = 0.0;
}

Book::Book(Book bookToCopy) {
    delete waitingList;
    waitingList = LinkedQueue<Person>(bookToCopy.waitingList);
    have = bookToCopy.have;
    want = bookToCopy.want;
    price = bookToCopy.price;
    title = bookToCopy.title;
}

Book::~Book() {
    delete waitingList;
}

int Book::getHave() {
    return have;
}

int Book::getWant() {
    return want;
}

double Book::getPrice() {
    return price;
}

std::string Book::getTitle() {
    return title;
}

void Book::setHave(int newHave) {
    have = newHave;
}

void Book::setWant(int newWant) {
    want = newWant;
}

void Book::setTitle(std::string newTitle) {
    title = newTitle;
}

void Book::setPrice(double newPrice) {
    price = newPrice;
}

int Book::calculateRestock() {
    int difference = want - have;
    if(difference<0) difference = 0;
    return difference;
}

void Book::restock(int numNewCopies) {
    have += numNewCopies;
}

void Book::addToWaitingList(Person person) {
    waitingList.enqueue(person);
}

