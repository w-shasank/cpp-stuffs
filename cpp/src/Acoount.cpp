#include "Account.hpp"

Account::Account(const std::string& p, int b) : pin(p), balance(b) {}

bool Account::checkPIN(const std::string& enteredPIN) const {
    return pin == enteredPIN;
}

int Account::getBalance() const {
    return balance;
}

void Account::withdraw(int amount) {
    if (amount <= balance) balance -= amount;
}
