#include "AddCredit.h"
#include "InputParser.h"
#include <iostream>
#include <string>
#include "UserManager.h"


void AddCredit::addCredit() {
	std::cout << "Enter amount of credit to add: ";
	// Get user input for amount of credit to add
	double amount;
	try {
		std::cin >> amount;
	} catch (...) {
		std::cout << "Amount must be a number between 0.01-1000.00"
				  << std::endl;
	}

	if (loggedInUser.getType() == "AA") {
		// Admin User: Get user input on username of account to add credit to
		std::cout << "Enter username of account to add credit to: ";
		std::string username;
		std::cin >> username;
		if (username == "") {
			// Blank username entered
			std::cout << "Username cannot be blank" << std::endl;
		} else if (!UserManager::exists(username)) {
			// Entered user does not exist
			std::cout << "User does not exist" << std::endl;
		} else {
			// User exists
			addCredit(UserManager::getUser(username), amount);
		}
	} else {
		// Non-Admin User: Add credit to own account
		addCredit(loggedInUser, amount);
	}
}

void AddCredit::addCredit(User user, double amount) {
	if (amount <= 0.00 || amount > 1000.00) {
		// Check amount constraints
		std::cout << "Amount must be a number between 0.01-1000.00"
				  << std::endl;
	} else if (amount > sessionCreditLimit) {
		// Can only add up to $1000.00 per given session
		std::cout << "You may only add up to $1000.00 of credit per session"
				  << std::endl;
	} else if ((user.getBalance() + amount) > 999999.99) {
		// User's credit balance will surpass account hard limit
		std::cout << "You may only have up to $999999.99 of credit"
				  << std::endl;
	} else {
		// Add the amount to the user's credit balance
		user.addCredit(amount);
		addTransaction("06 " + 
			InputParser::parseTransacName(user.getName()) + " " + 
			user.getType() + " " + 
			InputParser::parseTransacAmount(user.getBalance()));
	}
}
