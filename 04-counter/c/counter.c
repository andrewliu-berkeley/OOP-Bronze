#include "counter.h"

struct Counter {
    int value;
};

Counter* CounterConstructor() {
    Counter* counter = malloc(sizeof(Counter));
    counter->value = 0;
    return counter;
}

void CounterDestructor(Counter** counter) {
    free(*counter);
    *counter = NULL;
}

void increment(Counter* counter) {
    counter->value++;
}
void decrement(Counter* counter) {
    if (counter->value == 0) {
        printf("Counter value is already 0. Not decrementing.\n");
        return;
    }
    counter->value--;
}

void reset(Counter* counter) {
    counter->value = 0;
}

int getValue(const Counter* counter) {
    return counter->value;
}
