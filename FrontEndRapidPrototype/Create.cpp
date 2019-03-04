#include "Create.h"
#include "InputParser.h"
#include <iostream>
#include <string>
#include "User.h"
#include "UserManager.h"

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
		std::string strBalance;
		std::cout << "Please enter a new username:" << std::endl;
		std::getline(std::cin, username);
		if(UserManager::exists(username)){
			throw new TransactionException("Username already exists.");
		}
		//Checks if username is valid
		if (username.size() > 15 || username.size() < 1) {
            throw new TransactionException("Username wrong size.");
		}
		std::cout << "Please enter the users type:" << std::endl;
		std::getline(std::cin, type);
		if(!User::isValidType(type)){
			throw new TransactionException("Invalid type.");
		}
		std::cout << "Please enter the users balance:" << std::endl;
		std::getline(std::cin, strBalance);
		double balance = -1;
		try {
			balance = std::stod(strBalance);
		} catch (...) {}
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
