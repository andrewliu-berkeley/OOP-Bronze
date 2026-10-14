#include <cstdlib>
#include <iostream>
#include <string>

#include "bank_account.hpp"

static void check (bool status, const std::string& message)
{
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main (void){
    Account account(100'000);
    account.deposit(50'000);
    check(account.get_balance() == 150'000, "Balance should be 150,000 after deposit");
    account.withdraw(20'000);
    check(account.get_balance() == 130'000, "Balance should be 130,000 after withdrawal");

    bool blocked = false;
    try {
        account.withdraw(1'000'000);
    } catch (const std::invalid_argument&) {
        blocked = true;
    }
    check(blocked, "Withdrawal should be blocked");
    check(account.get_balance() == 130'000, "Balance should be 130,000 after withdrawal");

    std::cout << "All tests passed!" << std::endl;
}
