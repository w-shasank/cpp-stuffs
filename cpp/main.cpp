#include <SFML/Graphics.hpp>
#include "ATM.hpp"

int main() {
    ATM atm("1234", 5000);

    if (atm.authenticate("1234")) {
        std::cout << "Authenticated!\n";
        std::cout << "Balance: " << atm.getBalance() << "\n";
        atm.withdraw(1000);
        std::cout << "Balance after withdrawal: " << atm.getBalance() << "\n";
    } else {
        std::cout << "Incorrect PIN\n";
    }

    // Later you can integrate this logic with SFML buttons and inputs
    return 0;
}
