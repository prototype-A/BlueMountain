#include "TransactionException.h"
#include "User.h"


User::User() {
	// Dummy User (Not logged in)
	this->name = "";
	this->credit = 0;
	this->type = Type::BS;
}

User::User(std::string name, std::string type, double balance) {
	this->name = name;
	this->credit = balance;
	if (type.compare("AA") == 0) {
		this->type = Type::AA;
	} else if (type.compare("BS") == 0) {
		this->type = Type::BS;
	} else if (type.compare("FS") == 0) {
		this->type = Type::FS;
	} else if (type.compare("SS") == 0) {
		this->type = Type::SS;
	}
}

/**
 * Adds a specified amount of credit (no more than
 * 1000.00) to the user account's balance
 * 
 * @param amount The amount of credit to add
 * @throw A string exception if the addCredit() could not be completed
 */
void User::addCredit(double amount) {
	if (amount < 0 || amount > 1000) {
		// Amount of credit is out of range (< 0.00 or > 1000.00)
		throw new TransactionException("Amount must be a number between $0.00-$1000.00");
	} else if ((credit + amount) > 999999.99) {
		// User will have more than 999999.99 of credit
		throw new TransactionException("Amount too high");
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
		default: return "";
	}
}

bool User::isValidType(std::string type) {
	if(type.compare("Admin")==0 || 
	type.compare("full-standard")==0 || 
	type.compare("sell-standard")==0 || 
	type.compare("buy-standard")==0) {
		return true;
	}
	return false;
}
void User::setName(std::string n){
	name = n;
}
void User::setType(Type t){
	type = t;
}
