#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StudentRecord StudentRecord;

StudentRecord *StudentRecordConstructor(const char *name, int age, double gpa);

bool isPassed(StudentRecord *record);

char* summary(StudentRecord *record);

void StudentRecordDestructor(StudentRecord **record);

#endif
