#include "bank_account.hpp"
#include <stdexcept>

Account::Account(uint64_t balance) {
    if (balance <= 0) {
        throw std::invalid_argument("Initial balance cannot be negative");
    }
    this->balance = balance;
}

Account::~Account() {

}

void Account::deposit(uint64_t amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount cannot be negative");
    }
    this->balance += amount;
}

void Account::withdraw(uint64_t amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdraw amount cannot be negative");
    }
    if (amount > balance) {
        throw std::invalid_argument("Cannot withdraw more than balance");
    }
    this->balance -= amount;
}

uint64_t Account::get_balance() {
    return this->balance;
}
