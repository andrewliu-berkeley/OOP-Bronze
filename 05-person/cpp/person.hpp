#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
public:
    Person(std::string name, int age);
    const std::string& getName() const;
    int getAge() const;
    std::string greet(Person &other) const;

private:
    std::string name;
    int age;
};

#endif
