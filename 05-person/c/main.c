#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

static void check (bool status, const char* message) {
    if (!status) {
        fprintf(stderr, "Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main (void){
    Person *person = PersonConstructor("An", 24);
    check(person != NULL, "PersonConstructor return NULL, name or age is invalid");
    check(strcmp(getName(person), "An") == 0, "getName return unexpected value");
    check(getAge(person) == 24, "getAge return unexpected value");
    check(getName(person) != NULL, "getName return NULL");

    Person *person2 = PersonConstructor("Binh", 25);
    check(person2 != NULL, "PersonConstructor return NULL, name or age is invalid");
    check(strcmp(getName(person2), "Binh") == 0, "getName return unexpected value");
    check(getAge(person2) == 25, "getAge return unexpected value");

    greet(person, person2);

    PersonDestructor(&person);
    PersonDestructor(&person2);

    check(person == NULL, "PersonDestructor did not set pointer to NULL");
    check(person2 == NULL, "PersonDestructor did not set pointer to NULL");

    printf("All tests passed\n");

}
