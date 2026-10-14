#include "person.h"

struct Person {
    const char *name;
    int age;
};

Person *PersonConstructor(const char *name, int age) {
    Person *person = malloc(sizeof(Person));
    if (name == NULL || name[0] == '\0') {
            return NULL;
    }
    if (age < 0) {
        return NULL;
    }
    person->name = name;
    person->age = age;
    return person;
}

void PersonDestructor(Person **person) {
    free(*person);
    *person = NULL;
}

const char *getName(const Person *person) {
    return person->name;
}

int getAge(const Person *person) {
    return person->age;
}

void greet(const Person *person, const Person *other){
    printf("%s greets %s\n", person->name, other->name);
}
