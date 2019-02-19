#include <cmath>
#include "InputParser.h"
#include <iostream>
#include "Transaction.h"
#include "UserManager.h"


/**
 * Parses the specified string input and determines 
 * which transaction to invoke
 *
 * @param input The input to parse
 */
void InputParser::parseTransaction(std::string input) {
	if (input.compare("login") == 0) {
		std::cout << "login" << std::endl;
	} else if (input.compare("logout") == 0) {
		std::cout << "logout" << std::endl;
	} else if (input.compare("create") == 0) {
		std::cout << "create" << std::endl;
	} else if (input.compare("delete") == 0) {
		std::cout << "delete" << std::endl;
	} else if (input.compare("buy") == 0) {
		std::cout << "buy" << std::endl;
	} else if (input.compare("addcredit") == 0) {
		std::cout << "addcredit" << std::endl;
	} else if (input.compare("refund") == 0) {
		std::cout << "refund" << std::endl;
	} else if (input.compare("sell") == 0) {
		std::cout << "sell" << std::endl;
	} else {
		std::cout << "Invalid transaction" << std::endl;
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
	if (name.compare("") == 0) {
		// Blank username entered
		throw new TransactionException("Username cannot be blank");
	} else if (!UserManager::exists(name)) {
		// User does not exist
		throw new TransactionException("Account does not exist");
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
std::string InputParser::padNumAmount(int amount, int len) {
	std::string strAmount = std::to_string(amount);

	// Balance is already len characters
	if (strAmount.length() == len) {
		return strAmount;
	}

	// Pad balance to len characters
	for (int i = 0; i < len - strAmount.length(); i++) {
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
std::string InputParser::padNumAmount(double amount, int len) {
	std::string strAmount = std::to_string(amount);

	// Add ".00", if amount of cents is 0
	if (ceil(amount) == floor(amount)) {
		strAmount += ".00";
	}

	// Balance is already len characters
	if (strAmount.length() == len) {
		return strAmount;
	}

	// Pad balance to 9 characters
	for (int i = 0; i < len - strAmount.length(); i++) {
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
std::string InputParser::padString(std::string str, int len) {
	// String is already of specified length
	if (str.length() == len) {
		return str;
	}

	// Pad str to len characters with spaces at the end
	std::string paddedStr = str;
	for (int i = 0; i < len - str.length(); i++) {
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
