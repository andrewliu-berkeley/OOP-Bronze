#ifndef COUNTER_H
#define COUNTER_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Counter Counter;

Counter* CounterConstructor();
void increment(Counter* counter);
void decrement(Counter* counter);
void reset(Counter* counter);
int getValue(const Counter* counter);
void CounterDestructor(Counter** counter);


#endif
