#include "Transaction.h"
#include <iostream>
#include "UserManager.h"
#include "InputParser.h"
#include <string>
class Delete : public Transaction{
public:
	/*
	 * Displays prompts to allow the currently
	 * logged-in admin user to delete a user from the system
	 * and records this transaction for later printing in the
	 * daily tranaction file.
	 */
	void deleteUser() {
		std::string username;
		std::cout << "Please enter a username you wish to delete.";
		std::cin >> username;
		if (UserManager::exists()) {
			std::cout << "Delete successful!";
			User username = UserManager::getUser(username);
			addTransaction(username);
		}
		else {
			std::cout << "User does not exist.";
		}
	};
	void Delete::addTransaction(User user) {
		std::string username = InputParser::parseTransacName(user.getName());
		std::string deleteTransaction = "05_" + username + "_" ;
		Transaction::addTransaction(deleteTransaction);
	}
};