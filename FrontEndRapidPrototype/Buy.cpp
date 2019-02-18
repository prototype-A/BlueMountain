#include "Buy.h"
#include "InputParser.h"
#include <iostream>
#include <string>


void Buy::buyTickets() {
	try {
		// Check if sell-only account
		if (loggedInUser.getType() == "SS") {
			std::cout << "This account does not have the ability to "
					  << "purchase tickets" << std::endl;
			return;
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
		if (numTickets > 4 && loggedInUser.getType().compare("AA") != 0) {
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
		if (sellerName.compare("") == 0) {
			// Seller username is empty
			throw new TransactionException("Seller's username cannot be blank");
		}

		/*
		 * TODO:- Handle case for not enough credit on user account to buy tickets
		 *		- Handle case for not enough tickets to fulfil order
		 * 		- Handle actual purchase transaction
		 */

	} catch (TransactionException e) {
		// Invalid input during transaction
		std::cout << e.what() << std::endl;
	} catch (...) {
		// Unexpected exception occurred during transaction
		std::cout << "An error occurred. Please try again." << std::endl;
	}
}

void Buy::addTransaction(std::string eventName, int numTickets, double ticketPrice) {
	std::string buyTransaction = "04 " + 
		InputParser::parseTransacEventName(eventName) + " " + 
		InputParser::parseTransacTickets(numTickets) + " " + 
		InputParser::parseTransacTicketPrice(ticketPrice);

	Transaction::addTransaction(buyTransaction);
}