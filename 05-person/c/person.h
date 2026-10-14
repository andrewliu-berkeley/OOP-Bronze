#ifndef PERSON_H
#define PERSON_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Person Person;

Person* PersonConstructor(const char* name, int age);
const char* getName (const Person* person);
int getAge(const Person* person);
void greet(const Person* person, const Person* other);

void PersonDestructor(Person** person);

#endif
