//
// Created by ysupe on 12/1/2017.
//
#include "Person.h"
Person::Person() {
    this->name = "";
    this->number = "";
    this->email = "";
    this->preference = "";
}
std::string Person::getName() {
    return name;
}
std::string Person::getNumber(){
    return number;
}
std::string Person::getEmail(){
    return email;

}
std::string Person::getPreference() {
    return preference;
}

void Person::setName(std::string nameIn) {
    this->name=nameIn;
}
void ::Person::setNumber(std::string numberIn) {

}


