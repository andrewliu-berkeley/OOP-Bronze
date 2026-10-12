#include <stdio.h>
#include <stdbool.h>
#include "counter.h"


static void check (bool status, const char* message) {
    if (!status) {
        printf("Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main (void){
    Counter* counter = CounterConstructor();
    check(counter != NULL, "CounterConstructor return NULL, failed to create counter");
    check(getValue(counter) == 0, "Counter value should be 0 after creation");

    increment(counter);
    increment(counter);
    check(getValue(counter) == 2, "Counter value should be 2 after two increments");

    decrement(counter);
    check(getValue(counter) == 1, "Counter value should be 1 after decrement");

    reset(counter);
    check(getValue(counter) == 0, "Counter value should be 0 after reset");

    decrement(counter);
    check(getValue(counter) == 0, "Counter value should be 0 after decrement on reset");

    CounterDestructor(&counter);
    check(counter == NULL, "Counter should be NULL after destructor");

    printf("All tests passed!\n");
}
