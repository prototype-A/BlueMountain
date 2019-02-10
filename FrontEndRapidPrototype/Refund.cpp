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
	std::cout << "Enter the username of buyer account: ";
	std::string buyerName;
	std::cin >> buyerName;
	if (UserManager::exists(buyerName)) {
		std::cout << "Account does not exist" << std::endl;
		return;
	}
	User buyer = UserManager::getUser(buyerName);

	std::cout << "Enter the username of seller account: ";
	std::string sellerName;
	std::cin >> sellerName;
	if (UserManager::exists(sellerName)) {
		std::cout << "Account does not exist" << std::endl;
		return;
	}
	User seller = UserManager::getUser(sellerName);

	std::cout << "Enter the amount to refund: ";
	double refundAmount;
	std::cin >> refundAmount;


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
	try {
		buyer.addCredit(amount);
		seller.removeCredit(amount);

		addTransaction(buyer, seller, amount);
	} catch (std::string e) {
		std::cout << e << std::endl;
	}
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
	std::string buyerName = InputParser::parseTransacName(buyer.getName());
	std::string sellerName = InputParser::parseTransacName(seller.getName());
	std::string transacAmount = InputParser::parseTransacAmount(amount);
	std::string refundTransaction = "05_" + buyerName + "_" +
									 sellerName + "_" + 
									 transacAmount;
	Transaction::addTransaction(refundTransaction);
}
