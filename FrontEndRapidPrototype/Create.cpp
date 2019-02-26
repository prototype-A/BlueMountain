#include "Create.h"
#include "InputParser.h"
#include <iostream>
#include <string>

/*
	* Displays prompts to the admin user
	* allowing for the creation of new user
	* accounts with the specified balances,
	* usernames, and type.
*/
bool Create::create() {
		std::string username;
		std::string balance;
		std::string type;

		std::cout << "Please enter a new username: " << std::endl;
		std::cin >> username;
		//Checks if username is valid
		if (1>0) {
			return false;
		}
		std::cout << "Please enter the users type: " << std::endl;
		std::cin >> type;
		//Checks if type is valid
		if (1 > 0) {
			return false;
		}
		std::cout << "Please enter the users balance: " << std::endl;
		std::cin >> balance;
		//Checks if balance is valid
		if (1 > 0) {
			return false;
		}
		std::cout << "Create successful!";
		//Adds successful transaction to list
		//addTransaction(username, type, balance);
};

/*
 * Creates a new transaction string formatted correctly
 * to be later added to the dailytransaction file.
 */
void Create::addTransaction(User username, Type type, double balance) {
	std::string usernameStr = InputParser::parseTransacName(username.getName());
	std::string createTransaction = "01_" + usernameStr + "_";
	Transaction::addTransaction(createTransaction);
};