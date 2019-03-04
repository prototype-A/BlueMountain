#include "Create.h"
#include "InputParser.h"
#include <iostream>
#include <string>
#include "User.h"

/*
	* Displays prompts to the admin user
	* allowing for the creation of new user
	* accounts with the specified balances,
	* usernames, and type.
*/
void Create::create() {
        //Check if the user is logged
        if (!Transaction::isLoggedIn()) {
            throw new TransactionException("Not Logged In");
        }
		std::string username;
		std::string type;
		double balance;
		std::cout << "Please enter a new username: ";
		// Ignore the newline from initiating transaction
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		std::getline(std::cin, username);
		//Checks if username is valid
		if (username.size() > 15 || username.size() < 1) {
            throw new TransactionException("Username wrong size.");
		}
		std::cout << "Please enter the users type: ";
		std::cin >> type;
		std::cout << "Please enter the users balance: ";
		std::cin >> balance;
		//Checks if balance is valid
		if (balance > 999999.99) {
			throw new TransactionException("Balance too large.");
		} else if (balance < 0) {
			throw new TransactionException("Balance too small.");
		}
		std::cout << "Create successful!" << std::endl;
		//Creates the user with the data
		User user(username, type, balance);

		//Adds successful transaction to list
		addTransaction(user, balance);
};

/*
 * Creates a new transaction string formatted correctly
 * to be later added to the dailytransaction file.
 */
void Create::addTransaction(User user, double balance) {
	std::string username = InputParser::parseTransacName(user.getName());
	std::string createTransaction = "01_" + username + "_" + user.getType() + "_" + std::to_string(user.getBalance());
	Transaction::addTransaction(createTransaction);
};
