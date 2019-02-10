#include <string>
#include "User.h"


/**
 * Adds a specified amount of credit (no more than
 * 1000.00) to the user account's balance
 * 
 * @param amount The amount of credit to add
 * @throw A string exception if the addCredit() could not be completed
 */
void User::addCredit(double amount) {
	if (amount <= 0 || amount <= 1000) {
		// Amount of credit is out of range (0.01-1000.00)
		throw "Amount must be a number between 0.01-1000.00";
	} else if ((credit + amount) > 999999.99) {
		// User will have more than 999999.99 of credit
		throw "Amount too high";
	} else {
		credit += amount;
	}
}

/**
 * Removes from the user account balance
 * the specified amount of credit
 *
 * @param amount The amount of credit to remove
 * @throw A string exception if the removeCredit() could not be completed
 */
void User::removeCredit(double amount) {
	if (amount < 0) {
		// Amount of credit is negative
		throw "Amount must be positive";
	} else if ((credit - amount) < 0) {
		// User will have less than 0 credit
		throw "Amount too high";
	} else {
		credit -= amount;
	}
}

/**
 * Returns the amount of credit in the user's account
 *
 * @return The credit balance in the account
 */
double User::getBalance() {
	return credit;
}

/**
 * Returns the username of the account
 *
 * @return The string username of the account
 */
std::string User::getName() {
	return name;
}

/**
 * Returns the type of the user account
 *
 * @return The type of the user account as a string
 */
std::string User::getType() {
	switch(type) {
		case Type::AA: return "AA";
		case Type::FS: return "FS";
		case Type::SS: return "SS";
		case Type::BS: return "BS";
	}
}
