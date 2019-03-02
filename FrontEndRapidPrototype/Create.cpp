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
        if(!Transaction::isLoggedIn()){
            throw new TransactionException("Not Logged In");
        }
		std::string username;
		std::string balance;
		std::string strtype;
		Type type;
		std::cout << "Please enter a new username: " << std::endl;
		std::cin >> username;
		//Checks if username is valid
		if (username.size()>15 | username.size()<1) {
            throw new TransactionException("Username wrong size.");
		}
		std::cout << "Please enter the users type: " << std::endl;
		std::cin >> strtype;
		//Checks if type is valid
		if (strtype.compare("AA")) {
			type = AA;
		}else if(strtype.compare("BS")){
			type = BS;
		}else if(strtype.compare("FS")){
			type = FS;
		}else if(strtype.compare("SS")){
			type = SS;
		}else{
			throw new TransactionException("Not a valid type.");
		}
		std::cout << "Please enter the users balance: " << std::endl;
		std::cin >> balance;
		//Checks if balance is valid
		if (std::stod(balance) > 999999.99) {
			throw new TransactionException("Balance too large.");
		} else if (std::stod(balance) < 0) {
			throw new TransactionException("Balance too small.");
		}
		std::cout << "Create successful!";
		//Creates the user with the data
		User user;
		user.setName(username);
		user.addCredit(std::stod(balance));
		user.setType(type);

		//Adds successful transaction to list
		addTransaction(user, type, std::stod(balance));
};

/*
 * Creates a new transaction string formatted correctly
 * to be later added to the dailytransaction file.
 */
void Create::addTransaction(User user, Type type, double balance) {
	std::string username = InputParser::parseTransacName(user.getName());
	std::string createTransaction = "01_" + username + "_" + user.getType() + "_" + std::to_string(user.getBalance());
	Transaction::addTransaction(createTransaction);
};