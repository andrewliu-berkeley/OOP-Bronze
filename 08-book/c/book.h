#ifndef BOOK_H
#define BOOK_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Book Book;

Book* BookConstructor(const char* title, const char* author, int year);
void BookDestructor(Book** book);

void* Book_toString(Book* book, char* output, size_t output_size);

#endif
