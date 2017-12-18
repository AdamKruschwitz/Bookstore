//
// Created by Jeremy Timmins on 11/30/17.
//

#ifndef BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H
#define BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H

#include <iostream>
#include <string>
#include "Book.h"
#include "Bookstore.h"


class UserInterface {

private:
    Bookstore currentBookstore;

public:

    UserInterface();

    /**
     * displays all the keyboard shortcuts and what they do to help navigate
     * the bookstore
     * @post prints all of the commands
     */
    void help();
    /**
     * finds the matching book and lists the information about it
     * @param title is the string that user enters to search
     * @post prints all of the information on the book including the title, have and want
     * values , current price and the waiting list.
     */
    void inquire(std::string title);
    /**
     * lists the the information for the entire inventory
     * @post prints the information for the entire inventory of books
     */
    void list();
    /**
     * adds a book to the inventory
     * @param title which is the title of the book that needs to be added
     * @post adds the book name as well as information into the inventory
     */
    void add(std::string title);
    /**
     * changes the want value and price for a certain book
     * @param title is the name of the book whose want value is to be modified
     * @post modifies the want value and price to the one which the user enters
     */
    void modify(std::string title);
    /**
     * sells a single copy of the entered book
     * @param title is the name of the book which is to be sold
     * @post decreases the value of the book by one if in inventory or else adds the
     * person to the waiting list for that book
     */
    void sell(std::string title);
    /**
     * orders books for the entire library
     * @post when the order is received the want value for each book
     * is equivalent to the have value.
     */
    void order();
    /**
     * fulfills the orders of the bookstore
     * @param fileIn is the file that has the information of the books need
     * in the format of book, comma number of books.
     * @post adds the books the library, and if there are
     * people on the waiting list it gives the book to them.
     */
    void delivery(std::string fileIn);
    /**
     * gives back the extra books to seller
     * @param fileIn is the file that will hold the changes
     * @post outputs a file that has all the information about extra books.
     */

    void returnFunction();
    /**
     * Quits the function and ends the execution
     * @post saves the inventory and waitlist in a file and terminates execution
     */

    void quit();
    /**
     * Runs starts the loop for the menu
     * @post while not ebetering q the user interface runs
     */

    void run();

};


#endif //BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H
