#include <exception>
#include <string>
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

	class TransactionException : public std::exception {
		public:
			TransactionException(const char* errMsg) { this->errMsg = errMsg; }
			virtual const char* what() const throw() {
				return this->errMsg;
			}
		private:
			const char* errMsg;
	};
};
