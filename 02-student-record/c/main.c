#include "student_record.h"
#include <string.h>

static void check(bool status, const char *message) {
    if (!status) {
        printf("[FAIL]: %s\n", message);
        exit(1);
    }
}

int main(void){
    StudentRecord *student = StudentRecordConstructor("An", 20, 7.5);
    check(student != NULL, "StudentRecordConstructor return NULL, check the input parameters");

    check(isPassed(student), "Student must be passed");
    check(strcmp(summary(student), "Name: An, Age: 20, GPA: 7.50") == 0, "Summary must match");

    StudentRecord *student2 = StudentRecordConstructor("Binh", 21, 3.0);
    check(student2 != NULL, "StudentRecordConstructor return NULL, check the input parameters");
    check(!isPassed(student2), "Student must not be passed");
    check(strcmp(summary(student2), "Name: Binh, Age: 21, GPA: 3.00") == 0, "Summary must match");

    StudentRecordDestructor(&student);
    StudentRecordDestructor(&student2);
    check(student == NULL, "Student must be NULL after destructor");
    check(student2 == NULL, "Student2 must be NULL after destructor");

    printf("Everthing passed\n");
}
