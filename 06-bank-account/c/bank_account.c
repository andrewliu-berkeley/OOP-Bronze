#include "bank_account.h"
#include <stdint.h>

struct Account {
    uint64_t balance;
};

Account* AccountConstructor(uint64_t balance) {
    if (balance < 0) {
        return NULL;
    }
    Account* account = malloc(sizeof(Account));
    account->balance = balance;
    return account;
}

void AccountDestructor(Account** account) {
    free(*account);
    *account = NULL;
}

void* deposit(Account *account, uint64_t amount){
    if (amount <= 0) {
        return NULL;
    }
    account->balance += amount;
    return account;
}

void* withdraw(Account *account, uint64_t amount){
    if (amount <= 0) {
        return NULL;
    }
    if (account->balance < amount) {
        return NULL;
    }
    account->balance -= amount;
    return account;
}

uint64_t getBalance(const Account *account) {
    return account->balance;
}
