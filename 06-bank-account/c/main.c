#include <stdio.h>
#include <stdbool.h>
#include "bank_account.h"


static void check (bool status, const char* message) {
    if (!status) {
        fprintf(stderr, "Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

static void checkTrue (bool status, const char* message) {
    if (status) {
        fprintf(stderr, "Passed: %s\n", message);
    }
}


int main(void) {
    Account *account = AccountConstructor(100000);
    check(account != NULL, "AccountConstructor return NULL, check balance");
    deposit(account, 50000);
    check(getBalance(account) == 150000, "Deposit failed");
    withdraw(account, 20000);
    check(getBalance(account) == 130000, "Withdraw failed");

    check(withdraw(account, 180000) == NULL, "The withdrawal amount exceeds the balance. Must be blocked.");
    checkTrue(withdraw(account, 200000) == NULL, "The withdrawal amount exceeds the balance. Has been blocked.");
    check(getBalance(account) == 130000, "Balance should remain unchanged after blocked withdrawal.");

    AccountDestructor(&account);
    check(account == NULL, "Account should be NULL after destructor call.");

    printf("All tests passed.\n");
    return 0;

}
