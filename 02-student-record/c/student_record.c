#include "student_record.h"
#include <stdio.h>

struct StudentRecord {
    const char *name;
    int age;
    double gpa;
};

StudentRecord *StudentRecordConstructor(const char *name, int age, double gpa) {
    if (name == NULL) {
        return NULL;
    }
    if (age < 18) {
        return NULL;
    }
    if (gpa < 0.0 || gpa > 10.0) {
        return NULL;
    }
    StudentRecord *record = malloc(sizeof(StudentRecord));
    record->name = name;
    record->age = age;
    record->gpa = gpa;
    return record;
}

bool isPassed(StudentRecord *record) {
    return record->gpa >= 5.0;
}

char* summary(StudentRecord *record) {
    char *result = malloc(200);
    snprintf(result, 200, "Name: %s, Age: %d, GPA: %.2lf", record->name, record->age, record->gpa);
    return result;
}

void StudentRecordDestructor(StudentRecord **record) {
    free(*record);
    *record = NULL;
}
