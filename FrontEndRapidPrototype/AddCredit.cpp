#include "AddCredit.h"
#include "InputParser.h"
#include <iostream>
#include <string>
#include "UserManager.h"


void AddCredit::addCredit() {
	try {
		// Get user input for amount of credit to add
		std::cout << "Enter amount of credit to add: ";
		double amount;
		std::cin >> amount;

		if (amount <= 0.00 || amount > 1000.00) {
			// Check amount constraints
			throw new TransactionException("Amount must be a number between 0.01-1000.00");
		} else if (amount > sessionCreditLimit) {
			// Can only add up to $1000.00 per given session
			throw new TransactionException("You may only add up to $1000.00 of credit per session");
		}

		if (isType("AA")) {
			// Admin: Get user input on username of account to add credit to
			std::cout << "Enter username of account to add credit to: ";
			std::string username;
			std::cin >> username;
			InputParser::parseIsValidUsername(username);
			addCredit(UserManager::getUser(username), amount);
		} else {
			// Non-Admin: Add credit to own account
			addCredit(loggedInUser, amount);
		}
	} catch (TransactionException e) {
		// Invalid input during transaction
		std::cout << e.what() << std::endl;
	} catch (...) {
		// Unexpected exception occurred during transaction
		std::cout << "An error occurred. Please try again." << std::endl;
	}
}

void AddCredit::addCredit(User user, double amount) {
	// User's credit balance will surpass account hard limit
	if ((user.getBalance() + amount) > 999999.99) {
		throw new TransactionException("Users may only have up to $999999.99 of credit");
	}

	// Add the amount to the user's credit balance
	sessionCreditLimit -= amount;
	user.addCredit(amount);

	// Add completed transaction to list for current session
	addTransaction("06 " + 
		InputParser::parseTransacName(user.getName()) + " " + 
		user.getType() + " " + 
		InputParser::parseTransacAmount(user.getBalance()));
}
