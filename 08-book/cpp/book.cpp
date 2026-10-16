#include "book.hpp"
#include <ostream>
#include <sstream>

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), year(year) {
    if (title.empty()) {
        throw std::invalid_argument("title cannot be empty");
    }
    if (author.empty()) {
        throw std::invalid_argument("author cannot be empty");
    }
    if (year <= 1900 || year >= 2026) {
        throw std::invalid_argument("year must be between 1900 and 2025");
    }
}

std::string Book::toString() const {
    std::ostringstream out;
    out << this->title << " — " << this->author << " (" << this->year << ")";
    return out.str();
}

std::ostream& operator<<(std::ostream& os, const Book* book) {
    return os << book->toString();
}
