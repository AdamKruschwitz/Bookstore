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

    void setName(std::string nameIn);
    /**
     * sets the name of the person
     * @param name is the string that holds the persons name
     * @post name is updated and set
     */
    void setNumber(std::string numberIn);
    /**
     * sets the number of the person
     * @param number is the string that holds the persons number
     * @post number is updated and set
     */
    void setEmail(std::string emailIn);
    /**
     * sets the email of the person
     * @param email is the string that holds the persons name
     * @post email is updated and set
     */
    void setPreference(std::string preferenceIn);
    /**
     * sets the preference of the person
     * @param preference is the string that holds the persons preference either call, text, or email
     * @post preference is updated and set
     */
    std::string getPreferredContactInfo();


};



#endif //RANDOMBOOKNAMEGENERATOR_PERSON_H
