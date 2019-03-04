#include "InputParser.h"
#include <iostream>
#include <string>
#include "Refund.h"
#include "UserManager.h"


/*
 * Displays prompts to allow the currently 
 * logged-in admin user to refund an input 
 * amount of credit from one user (seller) 
 * account to another user (buyer) account
 */
void Refund::refund() {
	// Check if a user is logged in
	if (!isLoggedIn()) {
		throw new TransactionException("Please log in first");
	}

	// Non-admin accounts cannot issue refund transactions
	if (!isType("AA")) {
		throw new TransactionException("This account does not have the ability to issue refunds");
	}

	// Get user input for account to add credit to
	std::cout << "Enter the username of buyer account: ";
	std::string buyerName;
	std::getline(std::cin, buyerName);
	InputParser::parseIsValidUsername(buyerName);
	User buyer = UserManager::getUser(buyerName);

	// Get user input for account to remove credit from
	std::cout << "Enter the username of seller account: ";
	std::string sellerName;
	std::getline(std::cin, sellerName);
	InputParser::parseIsValidUsername(sellerName);
	User seller = UserManager::getUser(sellerName);

	// Get user input on 
	std::cout << "Enter the amount to refund: $";
	std::string strRefundAmount;
	std::getline(std::cin, strRefundAmount);

	// Convert user input to double
	double refundAmount = -1;
	try {
		refundAmount = stod(strRefundAmount);
	} catch (...) {}
	if (refundAmount < 0 || refundAmount > 999999.99) {
		// Cannot refund negative amount or more than account credit hard limit
		throw new TransactionException("Amount to refund must be a valid number between 0-999999.99");
	}

	// Issue refund
	refund(buyer, seller, refundAmount);
}


/**
 * Adds to the credit balance of the first User parameter
 * the specified double amount and subtracts from the 
 * credit balance that same amount from the second
 * User parameter
 *
 * @param buyer The user to add the amount of credit to
 * @param seller The user to remove the amount of credit from
 * @param amount The amount of credit to refund
 */
void Refund::refund(User buyer, User seller, double amount) {
	if ((buyer.getBalance() + amount) > 999999.99) {
		// Buyer's credit balance will go over account hard limit after refund
		throw new TransactionException("Buyer has too much credit in balance to issue refund");
	} else if ((seller.getBalance() - amount) < 0) {
		// Seller does not have enough credit to refund to buyer
		throw new TransactionException("Seller has insufficient credit to issue refund");
	}

	// Perform refund
	buyer.addCredit(amount);
	seller.removeCredit(amount);

	// Add completed transaction to list for current session
	addTransaction(buyer, seller, amount);
}


/**
 * Formats the completed refund transaction and writes it
 * to the daily transaction file
 * 
 * @param buyer The user to add the amount of credit to
 * @param seller The user to remove the amount of credit from
 * @param amount The amount of credit to refund
 */
void Refund::addTransaction(User buyer, User seller, double amount) {
	Transaction::addTransaction("05 " + 
		InputParser::parseTransacName(buyer.getName()) + " " +
		InputParser::parseTransacName(seller.getName()) + " " + 
		InputParser::parseTransacAmount(amount));
}
