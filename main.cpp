#include <iostream>
#include "book.h"

void testGetAndSetFunctions() {
    Book mobyDick = Book("Moby Dick");
    mobyDick.setPrice(19.99); // Price is 19.99
    mobyDick.setWant(10); // Want is 10
    mobyDick.setHave(3); // Have is 3
    mobyDick.setTitle("Gone With The Wind");
}

void testCopyConstructor() {

}

void testRestock() {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}