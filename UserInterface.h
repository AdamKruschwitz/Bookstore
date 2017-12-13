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

    void inquire(std::string title);

    void list();

    void add(std::string title);

    void modify(std::string title);

    void sell(std::string title);

    void order();

    void delivery(std::string fileIn);

    void returnFunction();

    void quit();

    void run();

};


#endif //BOOKSTORE_2_ELECTRIC_BOOGALOO_USERINTERFACE_H
