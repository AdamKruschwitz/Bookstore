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

std::string cleanTitle(std::string title) {
    std::string newTitle = "";
    std::locale loc;
    for(std::string::size_type i = 0; i < title.length(); i++) {
        newTitle += std::tolower(title[i], loc);
    }
    return newTitle;
}
// returns true if s1 is earlier alphabetically than s2. returns true if strings are equal
bool compareAlphabetically (std::string s1, std::string s2) {
    bool stringsEqual = true;
    bool out = s1.length() < s2.length();
    for(std::string::size_type i = 0; i < s1.length() && s2.length() && stringsEqual; i++) {
        if(s1[i] > s2[i]) {
            out = false;
            stringsEqual = false;
        }
        else if(s1[i] < s2[i]) {
            out = true;
            stringsEqual = false;
        }
    }
    return out;
}

bool Book::operator==(Book& other) {
    return ::cleanTitle(this->title) == ::cleanTitle(other.title);
}

bool Book::operator<(Book& other) {
    return compareAlphabetically(::cleanTitle(this->title), ::cleanTitle(other.title));
}

bool Book::operator>(Book& other) {
    return compareAlphabetically(::cleanTitle(other.title), ::cleanTitle(this->title));
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