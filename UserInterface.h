//
// Created by Jeremy Timmins on 11/30/17.
//

#ifndef BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H
#define BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H

#include <iostream>
#include "Book.h"
#include "Bookstore.h"


class UserInterface {

private:
    Bookstore currentBookstore;

public:

    UserInterface();


    void help();

    //void inquire(std::string title);

    void list();

    void add(Book& title);

    void modify(Book& title);

    void sell(Book& title);

    void order();

    void delivery();

    void returnFunction();

    void quit();

    void run();

};


#endif //BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H
