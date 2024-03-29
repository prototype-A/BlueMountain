#include "Delete.h"
#include <iostream>
#include "UserManager.h"
#include "InputParser.h"
#include <string>

/*
	* Displays prompts to allow the currently
    * logged-in admin user to delete a user from the system
	* and records this transaction for later printing in the
	* daily tranaction file.
*/
void Delete::deleteUser() {
    //Check if the user is logged
    if(!Transaction::isLoggedIn()){
        throw new TransactionException("Not Logged In");
    }
	std::string username;
	std::cout << "Please enter a username you wish to delete." << std::endl;
	std::getline(std::cin, username);
	if(!isType("AA")){
		throw new TransactionException("Not privilege user.");
	}
	if(loggedInUser.getName().compare(username)==0){
		throw new TransactionException("User logged in already!");
	}
	if (UserManager::exists(username)) {
		std::cout << "Delete successful!" <<std::endl;
		User user = UserManager::getUser(username);
		addTransaction(user);
	}
	else {
		throw new TransactionException("User does not exist.");
	}
};

/*
 * Creates a new transaction string formatted correctly
 * to be later added to the dailytransaction file.
 */
void Delete::addTransaction(User user) {
	Transaction::addTransaction("02 " + 
		InputParser::parseTransacName(user.getName()) + " " + 
		user.getType() + " " + 
		InputParser::parseTransacAmount(user.getBalance()));
};
