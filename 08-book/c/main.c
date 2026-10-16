#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "book.h"

static void check (bool status, const char *message) {
    if (!status) {
        printf("%s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main (void){
    Book *book = BookConstructor("De Men Phieu luu ky", "To Hoai", 1946);
    check(book != NULL, "BookConstructor return NULL, check title, author, year.");

    char book_str[100];
    check(strcmp((const char*)Book_toString(book, book_str, sizeof(book_str)), "De Men Phieu luu ky - To Hoai (1946)") == 0, "Book_toString return incorrect string");

    BookDestructor(&book);
    check(book == NULL, "BookDestructor did not set book to NULL");

    printf("All tests passed\n");
    return 0;
}
