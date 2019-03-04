#include <cmath>
#include <iostream>

#include "AddCredit.h"
#include "Buy.h"
#include "Create.h"
#include "Delete.h"
#include "InputParser.h"
#include "Login.h"
#include "Logout.h"
#include "Refund.h"
#include "Sell.h"
#include "UserManager.h"
#include "Transaction.h"


/**
 * Parses the specified string input and determines 
 * which transaction to invoke
 *
 * @param input The input to parse
 */
void InputParser::parseTransaction(std::string input) {
	try {
		if (input.compare("login") == 0) {
			Login* loginTransaction = new Login();
			loginTransaction->login();
		} else if (input.compare("logout") == 0) {
			Logout* logoutTransaction = new Logout();
			logoutTransaction->logout();
		} else if (input.compare("create") == 0) {
			Create* createUserTransaction = new Create();
			createUserTransaction->create();
		} else if (input.compare("delete") == 0) {
			Delete* deleteUserTransaction = new Delete();
			deleteUserTransaction->deleteUser();
		} else if (input.compare("buy") == 0) {
			Buy* buyTicketsTransaction = new Buy();
			buyTicketsTransaction->buyTickets();
		} else if (input.compare("addcredit") == 0) {
			AddCredit* addCreditTransaction = new AddCredit();
			addCreditTransaction->addCredit();
		} else if (input.compare("refund") == 0) {
			Refund* refundUserTransaction = new Refund();
			refundUserTransaction->refund();
		} else if (input.compare("sell") == 0) {
			Sell* sellTicketsTransaction = new Sell();
			sellTicketsTransaction->sellTickets();
		} else if (input.compare("quit") == 0) {
			exit(0);
		} else {
			std::cout << "Invalid transaction" << std::endl;
		}
	} catch (TransactionException* e) {
		// Print error message
		std::cout << e->what() << std::endl;
	} catch (...) {
		// An unexpected exception occurred during transaction
		std::cout << "An error occurred. Please try again." << std::endl;
	}
}

/**
 * Returns the specified double amount as a string,
 * padded with 0's on the left (if needed) to fill
 * len characters
 *
 * @param amount The int amount to pad
 * @param len The length of the string to pad to
 * @return The string of the double amount, padded to len characters
 */
void InputParser::parseIsValidUsername(std::string name) {
	if (trim(name).compare("") == 0) {
		// Blank username entered
		throw new TransactionException("Username cannot be blank");
	} else if (!UserManager::exists(name)) {
		// User does not exist
		throw new TransactionException("Account does not exist");
	}
}

/**
 * Removes trailing chara from the specified string
 *
 * @param stringToTrim The string to remove trailing whitespace from
 * @return The whitespace-trimmed string
 */
std::string InputParser::trim(std::string stringToTrim) {
	for (int i = stringToTrim.length() - 1; i >= 0; i--) {
		if (stringToTrim.at(i) != ' ') {
			return stringToTrim.substr(0, i + 1);
		}
	}

	return "";
}

/**
 * Returns the specified double amount as a string,
 * padded with 0's on the left (if needed) to fill
 * len characters
 *
 * @param amount The int amount to pad
 * @param len The length of the string to pad to
 * @return The string of the double amount, padded to len characters
 */
std::string InputParser::padNumAmount(int amount, unsigned int len) {
	std::string strAmount = std::to_string(amount);

	// Balance is already len characters
	if (strAmount.length() == len) {
		return strAmount;
	}

	// Pad balance to len characters
	for (unsigned int i = 0; i < len - strAmount.length(); i++) {
		strAmount = " " + strAmount;
	}

	return strAmount;
}

/**
 * Returns the specified int amount as a string,
 * padded with 0's on the left (if needed) to fill
 * 3 characters
 *
 * @param amount The number of tickets
 * @return The padded string username of the account
 */
std::string InputParser::parseTransacTickets(int numTickets) {
	return padNumAmount(numTickets, 3);
}

/**
 * Returns the specified double amount as a string,
 * padded with 0's on the left (if needed) to fill
 * len characters
 *
 * @param amount The double amount to pad
 * @param len The length of the string to pad to
 * @return The string of the double amount, padded to len characters
 */
std::string InputParser::padNumAmount(double amount, unsigned int len) {
	std::string strAmount = std::to_string(amount);
	strAmount = strAmount.substr(0, strAmount.length() - 4);

	// Add ".00", if amount of cents is 0
	if (ceil(amount) == floor(amount)) {
		return strAmount;
	}

	// Pad balance to 9 characters
	for (unsigned int i = 0; i < len - strAmount.length(); i++) {
		strAmount = " " + strAmount;
	}

	return strAmount;
}

/**
 * Returns the price of a ticket as a string,
 * padded with 0's on the left (if needed) to fill
 * 6 characters
 *
 * @param amount The price of one ticket
 * @return The padded string
 */
std::string InputParser::parseTransacTicketPrice(double price) {
	return padNumAmount(price, 6);
}

/**
 * Returns the specified double amount as a string,
 * padded with 0's on the left (if needed) to fill
 * 9 characters
 *
 * @param amount The credit amount double
 * @return The padded string
 */
std::string InputParser::parseTransacAmount(double amount) {
	return padNumAmount(amount, 9);
}

/**
 * Returns the specified string padded with spaces 
 * on the right (if needed) to fill len characters
 *
 * @param str The string to pad
 * @param len The length to pad the string to
 * @return The string padded to len characters
 */
std::string InputParser::padString(std::string str, unsigned int len) {
	// String is already of specified length
	if (str.length() == len) {
		return str;
	}

	// Pad str to len characters with spaces at the end
	std::string paddedStr = str;
	for (unsigned int i = 0; i < len - str.length(); i++) {
		paddedStr += " ";
	}

	return paddedStr;
}

/**
 * Returns the specified string padded with spaces 
 * on the right (if needed) to fill 15 characters
 *
 * @param str The name of the user
 * @return The padded string username of the account
 */
std::string InputParser::parseTransacName(std::string name) {
	return padString(name, 15);
}

/**
 * Returns the specified string padded with spaces 
 * on the right (if needed) to fill 25 characters
 *
 * @param str The event name
 * @return The padded event name string
 */
std::string InputParser::parseTransacEventName(std::string name) {
	return padString(name, 25);
}
