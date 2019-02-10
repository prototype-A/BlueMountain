#include <cmath>
#include "InputParser.h"
#include <iostream>


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
 * 9 characters
 *
 * 
 * @return The padded string username of the account
 */
std::string InputParser::parseTransacAmount(double amount) {
	std::string creditBalance = std::to_string(amount);
	int len = 9;

	// Add ".00", if amount of cents is 0
	if (ceil(amount) == floor(amount)) {
		creditBalance += ".00";
	}

	// Balance is already 9 characters
	if (creditBalance.length() == len) {
		return creditBalance;
	}

	// Pad balance to 9 characters
	for (int i = 0; i < len - creditBalance.length(); i++) {
		creditBalance = " " + creditBalance;
	}

	return creditBalance;
}

/**
 * Returns the specified string padded with spaces 
 * on the right (if needed) to fill 15 characters
 *
 * @return The padded string username of the account
 */
std::string InputParser::parseTransacName(std::string name) {
	int len = 15;

	// Username is 15 characters already
	if (name.length() == len) {
		return name;
	}

	// Pad username to 15 characters with spaces
	std::string paddedName = name;
	for (int i = 0; i < len - name.length(); i++) {
		paddedName += " ";
	}

	return paddedName;
}
