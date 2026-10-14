#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP
#include <cstdint>
#include <stdint.h>

class Account {
public:
    explicit Account(uint64_t balance);
    ~Account();
    void deposit(uint64_t amount);
    void withdraw(uint64_t amount);
    uint64_t get_balance();

private:
    uint64_t balance;
};

#endif
