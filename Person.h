//
// Created by Adam Kruschwitz on 11/14/17.
//

#ifndef RANDOMBOOKNAMEGENERATOR_PERSON_H
#define RANDOMBOOKNAMEGENERATOR_PERSON_H
#include <string>

class Person {
private:
    std::string name;
    std::string number;
    std::string email;
    std::string preference;

public:
    Person();
    Person(std::string name,std::string number,std::string email,std::string preference);
    std::string getName();
    /**
    * gets the name of the Person
    * @returns the name of the person
    */
    std::string getNumber();
    /**
    * gets the number of the person
    * @returns the number of the person
    */
    std::string getEmail();
    /**
    * gets the email of the person
    * @returns the email of the person
    */
    std::string getPreference();
    /**
    * gets the preference of the person
    * @returns either call, text, or email, and the corresponding number or email
    */

    void setName(std::string Name);
    void setNumber(std::string Number);
    void setEmail(std::string Email);
    void setPreference(std::string Number);


};



#endif //RANDOMBOOKNAMEGENERATOR_PERSON_H
