#include <string>
#include "TransactionException.h"
#include "User.h"

class Transaction {
protected:
	Transaction();

    static User loggedInUser;
    static std::string transactions;

    bool isLoggedIn();
    void addTransaction(std::string transac);
    bool isType(std::string type);
    bool canBuy();
    bool canSell();
};
