#include "Buy.h"
#include "InputParser.h"
#include <iostream>


void Buy::buyTickets() {
	try {
		// Check if a user is logged in
		if (!isLoggedIn()) {
			throw new TransactionException("Please log in first");
		}

		// Check if sell-only account
		if (isType("SS")) {
			throw new TransactionException("This account does not have the ability to purchase tickets");
		}

		// Get user input for event name
		std::cout << "Enter the event name: ";
		std::string eventName = "";
		std::cin >> eventName;
		if (eventName.compare("") == 0) {
			// Event name is empty
			throw new TransactionException("Event name cannot be blank");
		} else if (eventName.length() > 25) {
			// Event name can't be longer than 25 characters in length
			throw new TransactionException("Event title can only be a maximum of 25 characters long");
		}

		// Get user input for number of tickets to purchase
		std::cout << "Enter number of tickets to purchase: ";
		int numTickets = 0;
		std::cin >> numTickets;
		if (numTickets > 4 && !isType("AA")) {
			// Standard users may only purchase up to 4 tickets
			throw new TransactionException("Standard users may only purchase a maximum of 4 tickets per session");
		} else if (numTickets <= 0) {
			// 0, negative or invalid amount of tickets to purchase entered
			throw new TransactionException("Number of tickets to purchase must be a positive number (maximum 4 for standard users)");
		}

		// Get user input for seller username
		std::cout << "Enter seller's username: ";
		std::string sellerName = "";
		std::cin >> sellerName;
		InputParser::parseIsValidUsername(sellerName);


		/*
		 * TODO:- Get ticket price for event
		 *		- Handle case for not enough credit on user account to buy tickets
		 *		- Handle case for not enough tickets to fulfil order
		 * 		- Handle actual purchase transaction
		 */


		// Transaction completed
		//addTransaction(eventName, sellerName, numTickets, ticketPrice);
	} catch (TransactionException e) {
		// Invalid input during transaction
		std::cout << e.what() << std::endl;
	} catch (...) {
		// Unexpected exception occurred during transaction
		std::cout << "An error occurred. Please try again." << std::endl;
	}
}

/**
 * Formats and adds the completed transaction to the
 * list of transactions made during current user session
 *
 * @param eventName The name of the event
 * @param sellerName The username of the seller account
 * @param numTickets The number of tickets for sale
 * @param ticketPrice The price of each ticket
 */
void Buy::addTransaction(std::string eventName,
						 std::string sellerName,
						 int numTickets,
						 double ticketPrice) {
	Transaction::addTransaction("04 " + 
		InputParser::parseTransacEventName(eventName) + " " + 
		InputParser::parseTransacName(sellerName) + " " +
		InputParser::parseTransacTickets(numTickets) + " " + 
		InputParser::parseTransacTicketPrice(ticketPrice));
}
