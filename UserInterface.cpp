//
// Created by Jeremy Timmins on 11/30/17.
//

#include "UserInterface.h"
#include <iostream>
#include "Book.h"
#include "Book.cpp"
using namespace std;

void help(){
    //lists commands
}

void inquire(Book& title){
    //Display info for a title
}

void list(){
    //list the info for the inventory
}

void add(Book& title){
    //Add a book to the inventory.
    // Prompt for initial want value
    // and have value.
    // If the title already exists,
    // inform the user and print the
    // information for that title.
}

void modify(Book& title){
    //Modify the want value for the specified title.
    // Display current want and have values,
    // and prompt user for new want value.

}

void sell(Book& title){
    //Decrease the count for the specified title by 1.
    // If the title doesn't exist yet, it should be added.
    // If the title is sold out (or didn't exist),
    // prompt the user for the buyer's information and
    // enter them on the wait list for that title.

}

void order(){
    //Needs file io
   //Create a bulk purchase order for
    // additional books based on a comparison
    // of the have and want values in the inventory.
    // For each book, enough books should be ordered
    // so that, when the order is received, the have value
    // will be equal to the want value.

}

void delivery(){
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

void returnFunction(){
    //needs file io still

    //Write a return invoice to a file specifying all
    // books to be returned. For each book, copies
    // should be returned if the have value is higher
    // than the want value. The system should change
    // the have value to equal the want value, and the
    // output file should then give the list of books
    // to take off the shelf and return.

}

void quit(){
    //Save the inventory and wait lists in a file and terminate execution.
}
void run(){

    std::string input ="";
    while (input != "q"){
        std::cout << "Welcome to BookStore 2: Electric Boogaloo!\n Please enter a command" << std::endl;

        getline(cin,input);

        //not sure if this works or not
        input = tolower(input);

        if (input=="h"){
            help();
        }
        if(input=="i"){
            //run inquire function
        }
        if(input=="l"){
            list();
        }
        if(input=="a"){
            //run add function
        }
        if(input=="m"){
            //run modify function
        }
        if(input=="s"){
            //run sell function
        }
        if(input=="o"){
            //run order function
        }
        if(input=="d"){
            //run delivery function
        }
        if(input=="r"){
            //run returnFunction
        }
        if(input=="q"){
            quit();
        }

    }
    //close file

}
