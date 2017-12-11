//
// Created by ysupe on 12/1/2017.
//
#include <iostream>
#include "Person.h"
Person::Person(std::string nameIn, std::string numberIn ,std::string emailIn ,std::string preferenceIn) {
    this->name = nameIn;
    this->number = numberIn;
    this->email = emailIn;
    this->preference = preferenceIn;
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
std::string Person::getPreferredContactInfo() {
    if (this->getPreference() == "call") {
        return "call "+ this->getNumber();
    } else if (this->getPreference() == "email") {
        return "email " + this->getEmail();
    } else {
        return "text " + this->getNumber();
    }

}
/*int main() {
    Person *test = new Person("customer", "3456789", "foo@gmail.com", "text");
    std::cout<<test->getNumber()<<std::endl;
    std::cout<<test->getName()<<std::endl;
    std::cout<<test->getEmail()<<std::endl;
    std::cout<<test->getPreferredContactInfo()<<std::endl;

    Person *test2 = new Person("customer2", "6547567822", "foo2@gmail.com", "call");
    std::cout<<test2->getNumber()<<std::endl;
    std::cout<<test2->getName()<<std::endl;
    std::cout<<test2->getEmail()<<std::endl;
    std::cout<<test2->getPreferredContactInfo()<<std::endl;
    Person *test3 = new Person("customer3", "6547567823", "foo3@gmail.com", "email");
    std::cout<<test3->getNumber()<<std::endl;
    std::cout<<test3->getName()<<std::endl;
    std::cout<<test3->getEmail()<<std::endl;
    std::cout<<test3->getPreferredContactInfo()<<std::endl;
}*/




