#include "book.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>


static void check (bool status, const std::string& message) {
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main (void) {
    Book* book = new Book("De Men Phieu luu ky", "To Hoai", 1946);
    check(book->toString() == "De Men Phieu luu ky — To Hoai (1946)", "toString() return incorrect");

    std::stringstream out;
    out << book;
    check(out.str() == "De Men Phieu luu ky — To Hoai (1946)", "operator<< return incorrect");

    delete(book);
    book = nullptr;
    check(book == nullptr, "book should be nullptr after free");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
