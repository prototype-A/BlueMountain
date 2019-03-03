#pragma once
#include <string>
#include "TransactionException.h"
#include "User.h"


class Transaction {
protected:
	Transaction();

    inline static User loggedInUser;
    inline static std::string transactions;

    bool isLoggedIn();
    void addTransaction(std::string transac);
    bool isType(std::string type);
    bool canBuy();
    bool canSell();
};
