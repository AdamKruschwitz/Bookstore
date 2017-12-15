//
// Created by Adam Kruschwitz on 11/14/17.
//

#include "Book.h"
#include <iostream>

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

Book::Book(Book& bookToCopy) {
    //delete waitingList;
    //need a new way to delete waitingList
    //waitingList.~LinkedQueue();
    waitingList = LinkedQueue<Person>(bookToCopy.waitingList);
    have = bookToCopy.have;
    want = bookToCopy.want;
    price = bookToCopy.price;
    title = bookToCopy.title;
}

Book& Book::operator=(const Book other) {
    waitingList = LinkedQueue<Person>(other.waitingList);
    have = other.have;
    want = other.want;
    price = other.price;
    title = other.title;
    return *this;
}

bool Book::operator==(Book& other) {
    return this->title == other.title;
}

bool Book::operator<(Book& other) {
    return this->title < other.title;
}

bool Book::operator>(Book& other) {
    return this->title > other.title;
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

void Book::addToWaitingList(Person& person) {
    waitingList.enqueue(person);
}

void Book::removeFromWaitingList() {
    Person removedPerson = waitingList.dequeue();
    std::string out = removedPerson.getName();
    out += "\npreferred contact method: ";
    out += removedPerson.getPreferredContactInfo();
    std::cout << out << std::endl;
}

LinkedQueue<Person> Book::getWaitingList() {
    LinkedQueue<Person> out = LinkedQueue<Person>(waitingList);
    return out;
}