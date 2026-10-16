#include "book.h"
#include <corecrt.h>

struct Book {
    char title[100];
    char author[100];
    int year;
};

Book* BookConstructor(const char* title, const char* author, int year) {
    if (title == NULL || strlen(title) == 0) {
        return NULL;
    }
    if (author == NULL || strlen(author) == 0) {
        return NULL;
    }
    if (year <= 1900 || year >= 2026) {
        return NULL;
    }
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy_s(book->title, sizeof(book->title), title);
    strcpy_s(book->author, sizeof(book->author), author);
    book->year = year;
    return book;
}

void BookDestructor(Book** book) {
    if (book != NULL) {
        free(*book);
        *book = NULL;
    }
}

void* Book_toString(Book *book, char *output, size_t output_size){
    sprintf_s(output, output_size, "%s - %s (%d)", book->title, book->author, book->year);
    return output;
}
