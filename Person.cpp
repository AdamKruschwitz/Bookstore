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
void Person::setNumber(std::string numberIn) {
    this->number=numberIn;
}
void Person::setEmail(std::string emailIn) {
    this->email=emailIn;

}
void Person::setPreference(std::string preferenceIn) {
    if(preferenceIn=="call"){
        this->preference="call";
    }
    else if(preferenceIn== "email"){
        this->preference="email";
    }
    else if(preferenceIn=="text"){
        this->preference="text";
    }
    //else


}
std:: string Person::getPreferredContactInfo() {
    if(this->getPreference()== "call"){
        return "call "<<this->getNumber();
    }
    else if(this->getPreference()=="email"){
        return "email "<<this->getEmail();
    }
    else{
        return "text "<<this->getNumber();
    }

}



