#include "InputParser.h"
#include <iostream>
#include "Sell.h"


void Sell::sellTickets() {
	try {
		// Check if buy-only account
		if (loggedInUser.getType().compare("BS") == 0) {
			std::cout << "This account does not have the ability to "
					  << "sell tickets" << std::endl;
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

		// Get user input for price of each ticket
		std::cout << "Enter price of each ticket: $";
		double ticketPrice = 0;
		std::cin >> ticketPrice;
		if (ticketPrice < 0 || ticketPrice > 999.99) {
			// Can only sell tickets for $0.00-999.99
			throw new TransactionException("Price of each ticket must be a number between 0.00-999.99");
		}

		// Get user input for number of tickets to sell
		std::cout << "Enter number of tickets to sell: ";
		int numTickets = 0;
		std::cin >> numTickets;
		if (numTickets <= 0 || numTickets > 100) {
			// Can only sell 1-100 tickets
			throw new TransactionException("Number of tickets to sell must be a positive number between 1-100");
		}


		/*
		 * TODO:- Handle actual sale transaction
		 */


		// Transaction completed
		addTransaction(eventName, numTickets, ticketPrice);
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
 * @param numTickets The number of tickets for sale
 * @param ticketPrice The price of each ticket
 */
void Sell::addTransaction(std::string eventName,
						  int numTickets,
						  double ticketPrice) {
	Transaction::addTransaction("03 " + 
		InputParser::parseTransacEventName(eventName) + " " + 
		InputParser::parseTransacName(loggedInUser.getName()) + " " +
		InputParser::parseTransacTickets(numTickets) + " " + 
		InputParser::parseTransacTicketPrice(ticketPrice));
}
