#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Account Account;

Account* AccountConstructor(uint64_t balance);
void AccountDestructor(Account** account);
void* deposit(Account* account, uint64_t amount);
void* withdraw(Account* account, uint64_t amount);
uint64_t getBalance(const Account* account);

#endif
