#ifndef BOOK_HPP
#define BOOK_HPP

#include <ostream>
#include <string>

class Book {
public:
    Book(const std::string& title, const std::string& author, int year);
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Book* book);

private:
    const std::string title;
    const std::string author;
    const int year;
};

#endif
