#include "person.hpp"
#include <stdexcept>

Person::Person(std::string name, int age) : name(name), age(age) {
    if (name.empty())
        throw std::invalid_argument("name must not be empty");
    if (age < 0)
        throw std::invalid_argument("age must not be negative");
}

const std::string& Person::getName() const {
    return this->name;
}

int Person::getAge() const {
    return this->age;
}

std::string Person::greet(Person &other) const {
    return this->name + " hello " + other.getName();
}
