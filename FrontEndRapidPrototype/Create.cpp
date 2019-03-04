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
		if (!isType("AA")){
			throw new TransactionException("Not privileged user.");
		}
		std::string username;
		std::string type;
		std::string balance;
		std::cout << "Please enter a new username:" << std::endl;
		std::getline(std::cin, username);
		//Checks if username is valid
		if (username.size() > 15 || username.size() < 1) {
            throw new TransactionException("Username wrong size.");
		}
		std::cout << "Please enter the users type:" << std::endl;
		std::cin >> type;
		if(!User::isValidType(type)){
			throw new TransactionException("Invalid type.");
		}
		std::cout << "Please enter the users balance:" << std::endl;
		std::cin >> balance;
		//Checks if balance is valid
		if (std::stod(balance) > 999999.99) {
			throw new TransactionException("Balance too large.");
		} else if (std::stod(balance) < 0) {
			throw new TransactionException("Balance too small.");
		}
		std::cout << "Create successful!" << std::endl;
		//Creates the user with the data
		User user(username, type, std::stod(balance));

		//Adds successful transaction to list
		addTransaction(user);
};

/*
 * Creates a new transaction string formatted correctly
 * to be later added to the dailytransaction file.
 */
void Create::addTransaction(User user) {
	Transaction::addTransaction("01 " + 
		InputParser::parseTransacName(user.getName()) + " " + 
		user.getType() + " " + 
		InputParser::parseTransacAmount(user.getBalance()));
};
