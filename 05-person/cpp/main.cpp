#include <iostream>
#include "person.hpp"


static void check (bool status, const std::string& message) {
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(1);
    }
}

int main (void) {
    Person p1("John", 30);
    check(p1.getName() == "John", "Name should be John");
    check(p1.getAge() == 30, "Age should be 30");

    Person p2("Jane", 25);
    check(p2.getName() == "Jane", "Name should be Jane");
    check(p2.getAge() == 25, "Age should be 25");

    check(p1.greet(p2) == "John hello Jane", "Greeting should be John hello Jane");
    check(p2.greet(p1) == "Jane hello John", "Greeting should be Jane hello John");

    std::cout << p1.greet(p2) << std::endl;
    std::cout << p2.greet(p1) << std::endl;

    std::cout << "All tests passed!" << std::endl;

}
