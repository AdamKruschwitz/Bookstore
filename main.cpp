#include <iostream>
#include "UserInterface.h"
#include "Book.h"
#include "UserInterface.h"


void testGetAndSetFunctions() {
    Book* mobyDick = new Book("Moby Dick");
    mobyDick->setPrice(19.99); // Price is 19.99
    mobyDick->setWant(10); // Want is 10
    mobyDick->setHave(3); // Have is 3
    mobyDick->setTitle("Gone With The Wind");
    bool passed = true;
    std::string reason = "no problems here";
    if(mobyDick->getTitle()!="Gone With The Wind") {
        passed = false;
        reason = "get title failed";
    }
    else if(mobyDick->getPrice()!=19.99) {
        passed = false;
        reason = "get price failed";
    }
    else if(mobyDick->getWant()!=10) {
        passed = false;
        reason = "get want failed";
    }
    else if(mobyDick->getHave()!=3) {
        passed = false;
        reason = "get have failed";
    }
    if(passed) {
        std::cout << "test passed" << std::endl;
    } else {
        std::cout << "test failed: " << reason << std::endl;
    }
}

void bookListTest () {
    BookList testList = BookList();
    Book* book1 = testList.insertBook("book2");
    Book* book2 = testList.insertBook("book1");
    Book* book3 = testList.insertBook("book2");

    Book* book4 = testList.getBook("book1");
    Book* book5 = testList.getBook("book2");
    Book* book6 = testList.getBook("book3");
    std::cout << (book1==book4) << std::endl;
    std::cout << (book2==book5) << std::endl;
    std::cout << (nullptr==book6) << std::endl;
    std::cout << (nullptr==book3) << std::endl;
    delete book1;
    delete book2;
    //delete book3;
    //delete book4;
    //delete book5;
    //delete book6;
}

void bookComparatorTest () {
    std::cout << "I started the tes" << std::endl;
    Book* book1 = new Book("book1");
    Book* book2 = new Book("book1");
    std::cout << "I made the books" << std::endl;
    Person person1 = Person();
    book1->addToWaitingList(person1);
    std::cout << (*book1==*book2) << std::endl;
}

void linkedQueueTest() {
    LinkedQueue<Person> test;
    Person* person1 = new Person();
    person1->setName("person1");
    test.enqueue(*person1);
}

int main() {
    /*
    linkedQueueTest();
    std::cout << "we made it past linkedQueue test" << std::endl;
    testGetAndSetFunctions();
    bookListTest();
    bookComparatorTest();
     */



    UserInterface ui;
    ui.run();

    return 0;
}
/*
int main() {
    testGetAndSetFunctions();

    Book* book1 = new Book("first");
    Book* book2 = new Book("second");

    std::cout << (book1==book2) << std::endl;



    UserInterface ui;
    ui.run();

    return 0;
}
 */