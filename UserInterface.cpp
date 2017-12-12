//
// Created by Jeremy Timmins on 11/30/17.
//

#include "UserInterface.h"
#include <iostream>
#include "Book.h"
//#include "ArrayList.h"
#include "BookList.h"
#include <fstream>
using namespace std;

UserInterface::UserInterface(){
     currentBookstore =  Bookstore();

}

void UserInterface::help(){
    //lists commands
    std::cout << "Keyboard shortcut \t command \t description" << std::endl;
    std::cout <<"i \t std::string nameIn = \"\",std::string numberIn = \"\",std::string emailIn = \"\",std::string preferenceIn = \"\" \t Displays information for a specified title" << std::endl;
    std::cout <<"l \t list \t List the information for the entire inventory (in alphabetical order)" << std::endl;
    std::cout <<"a \t add \t Adds a book to the inventory" << std::endl;
    std::cout <<"m \t modify \t Modify the values of a specified title" << std::endl;
    std::cout <<"s \t sell \t Decreases the count for a specified title by one" << std::endl;
    std::cout <<"o \t order \t Create a bulk purchase order for additional books based on how many are needed" << std::endl;
    std::cout <<"d \t delivery \t Take information from a file listing the delivery shipment of books" << std::endl;
    std::cout <<"r \t return \t Writes a return invoice to a file specifying all books to be returned" << std::endl;
    std::cout <<"q \t quit \t Saves the inventory and wait lists in a file and closes the program" << std::endl;

}

void UserInterface::inquire(std::string title){
    //find matching book
    //print out info
    Book* current = currentBookstore.findBook(title); //doesnt work yet

    std::cout << current->getTitle() << std::endl;
    std::cout << "Have Value = " << current->getHave()<< std::endl;
    std::cout << "Want Value = " << current->getWant() << std::endl;
    std::cout << "Current Price = $" << current->getPrice() << std::endl;
    std::cout << "Waiting List: ";
    Queue waitingList = current->getWaitingList();
    while(!waitingList.isEmpty()) {
        std::cout << waitingList.dequeue().getName() + ", ";
    }
    std::cout << std::endl;
}

std::string getBookInfo(Book* book) {
    std::string out = "";
    Queue<Person> waitingList = book->getWaitingList();
    out += book->getTitle() + ", ";
    out += "price: $" + std::to_string(book->getPrice());
    out += "have: " + std::to_string(book->getHave());
    out += "want: " + std::to_string(book->getWant());
    out += "waitlist: ";
    while(!waitingList.isEmpty()) {
        out+=waitingList.dequeue().getName();
    }
}

void UserInterface::list(){
    //list the info for the inventory
    for(int i = 0; i < currentBookstore.getLibrarySize(); i++) {
        std::cout << getBookInfo(currentBookstore.getBookAt(i));
    }
}

void UserInterface::add(std::string title){
    //Add a book to the inventory.
    // Prompt for initial want value
    // and have value.
    // If the title already exists,
    // inform the user and print the
    // information for that title.
    std::cout << "Please enter the title of the book you wish to add" << std::endl;

    std::string titleIn ="";
    getline(cin,titleIn);

    //check if book exists

    std::cout << "Please enter the want value" << std::endl;

    std::string wantIn = "";
    getline(cin,wantIn);

    std::cout << "Please enter the have value" << std::endl;

    std::string haveIn = "";
    getline(cin,haveIn);

    //Book currentBook = Book();

    Book* shit = currentBookstore.addBook(titleIn);
    //shit.



}

void UserInterface::modify(std::string title){
    //Modify the want value for the specified title.
    // Display current want and have values,
    // and prompt user for new want value.
    Book* currentBook = currentBookstore.findBook(title);
    std::cout << currentBook->getTitle() << std::endl;
    std::cout << "Want: " + std::to_string(currentBook->getWant()) << std::endl;
    std::cout << "Have: " + std::to_string(currentBook->getHave()) << std::endl;
    std::cout << "Price: " + std::to_string(currentBook->getPrice()) << std::endl;
    std::cout << "Enter new want value " << std::endl;
    std::string wantIn = "";
    getline(cin, wantIn);

    int intWantIn = stoi(wantIn);
    currentBook->setWant(intWantIn);
    std::cout << "Want value changed to " + std::to_string(intWantIn) << std::endl;

    std::cout << "Enter new price" << std::endl;
    std::string priceIn = "";
    getline(cin, priceIn);

    double doublePriceIn = atof(priceIn);
    currentBook->setPrice(doublePriceIn);
    std::cout << "Price changed to " + std::to_string(doublePriceIn) << std::endl;
}

void UserInterface::sell(std::string title){
    //Decrease the count for the specified title by 1.
    // If the title doesn't exist yet, it should be added.
    // If the title is sold out (or didn't exist),
    // prompt the user for the buyer's information and
    // enter them on the wait list for that title.

    Book* currentBook = currentBookstore.findBook(title);
    if(currentBook == nullptr) {
        std::cout << "Book not in library, added to library" << std::endl;
        currentBook = currentBookstore.addBook(title);
        currentBook->setWant(1);
        currentBook->setHave(0);
        currentBook->setPrice(19.99);
    }
    if(currentBook->getHave() < 1) {
        std::cout << "The book is out of stock, add user to waiting list" << std::endl;
        Person* toAdd = new Person();
        std::string name = "";
        std::string email = "";
        std::string number = "";
        std::string contact = "";

        std::cout << "enter customer's name" << std::endl;
        getline(cin, name);
        std::cout << "enter customer's email" << std::endl;
        getline(cin, email);
        std::cout << "enter customer's number" << std::endl;
        getline(cin, number);
        while(contact == "") {
            std::cout << "enter customer's preffered contact method (text, call, email)" << std::endl;
            getline(cin, contact);
            if(contact != "text" || contact != "call" || contact != "email") {
                contact = "";
                std::cout << "please enter 'text', 'call', or 'email'" << std::endl;
            }
        }

        toAdd->setName(name);
        toAdd->setEmail(email);
        toAdd->setNumber(number);
        toAdd->setPreference(contact);

        currentBook->addToWaitingList(*toAdd);
        std::cout << "user added to waiting list" << std::endl;

    }
    else {
        int currentHave = currentBook->getHave();
        currentBook->setHave(currentHave-1);
    }
}

void UserInterface::order(){
    //Needs file io
    //Create a bulk purchase order for
    // additional books based on a comparison
    // of the have and want values in the inventory.
    // For each book, enough books should be ordered
    // so that, when the order is received, the have value
    // will be equal to the want value.

}

void UserInterface::delivery(){
    //needs file io

    //Take information from a file listing the delivery
    // shipment of books.  The file will contain the title
    // and the count of each book included in the shipment.
    // Read the file, and update the have values in the inventory
    // accordingly (the employee will then shelve the actual books from the shipment).
    // Note that the program must add any item to the inventory if
    // the delivered title is not present in the current inventory (
    // for instance if an extra book not requested was delivered).

    //If there is a wait list for any books delivered, the needed
    // copies of that book should not be added to the inventory
    // or be put on shelves. Instead, the program should print the
    // title of the book and the information of the person it should be put on hold for.
    // The employee then calls, texts, or  emails (depending on customer preference)
    // to inform the person that their book is waiting, writes a note marking who is
    // picking up the book, and leaves the book by the counter. The book is then
    // considered sold (the person should be removed from wait list).


}

void UserInterface::returnFunction(){
    //needs file io still

    //Write a return invoice to a file specifying all
    // books to be returned. For each book, copies
    // should be returned if the have value is higher
    // than the want value. The system should change
    // the have value to equal the want value, and the
    // output file should then give the list of books
    // to take off the shelf and return.

    int librarySize = currentBookstore.getLibrarySize();
    for(int i = 0; i < librarySize; i++) {
        Book* currentBook = currentBookstore.getBookAt(i);
        int currentBookHave = currentBook->getHave();
        int currentBookWant = currentBook->getWant();
        int difference = currentBookHave - currentBookWant;
        if(difference > 0) {
            std::ofstream fout ("returnInvoice.txt");

            std::string output = "";
            output += currentBook->getTitle();
            output += ", return " + std::to_string(difference) + " copies.\n";
            fout << output;
        }
    }
    std::cout << "return invoice created in returnInvoice.txt" << std::endl;

}

void UserInterface::quit(){
    //Save the inventory and wait lists in a file and terminate execution.
}
void UserInterface::run(){


    std::string input ="";
    while (input != "q"){
        std::cout << "Welcome to BookStore 2: Electric Boogaloo!\n Please enter a command, or type in 'h' for help" << std::endl;

        getline(cin,input);

        //not sure if this works or not

        std::locale loc;
        std::string str=input;
        for (std::string::size_type i=0; i<str.length(); ++i)
            std::cout << std::tolower(str[i],loc);
        //input = std::tolower(input);

        if (input=="h"){
            help();
        }
        else if(input=="i"){
            std::cout << "Please type in a title to inquire about" << endl;
            getline(cin,input);
            //inquire(input);
            //run inquire function
        }
        else if(input=="l"){
            list();
        }
        else if(input=="a"){
            //run add function
        }
        else if(input=="m"){
            //run modify function
        }
        else if(input=="s"){
            //run sell function
        }
        else if(input=="o"){
            //run order function
        }
        if(input=="d"){
            //run delivery function
        }
        else if(input=="r"){
            //run returnFunction
        }
        else if(input=="q"){
            quit();
        }
        else {
            std::cout << "please enter a valid command. enter h for help" << std::endl;
        }

    }
    //close file

}
