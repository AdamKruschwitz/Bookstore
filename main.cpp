#include <iostream>
#include "Book.h"

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

void testCopyConstructor() {

}

void testRestock() {

}

int main() {
    testGetAndSetFunctions();
    return 0;
}