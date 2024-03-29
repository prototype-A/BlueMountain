#include "InputParser.h"
#include <iostream>
#include "Sell.h"


void Sell::sellTickets() {
	// Check if a user is logged in
	if (!isLoggedIn()) {
		throw new TransactionException("Please log in first");
	}

	// Check if buy-only account
	if (isType("BS")) {
		throw new TransactionException("This account does not have the ability to sell tickets");
	}

	// Get user input for event name
	std::cout << "Enter the event name: ";
	std::string eventName;
	std::getline(std::cin, eventName);
	if (eventName.compare("") == 0) {
		// Event name is empty
		throw new TransactionException("Event name cannot be blank");
	} else if (eventName.length() > 25) {
		// Event name can't be longer than 25 characters in length
		throw new TransactionException("Event title can only be a maximum of 25 characters long");
	}

	// Get user input for price of each ticket
	std::cout << "Enter price of each ticket: $";
	std::string strTicketPrice;
	std::getline(std::cin, strTicketPrice);

	// Convert user input to double
	double ticketPrice = -1;
	try {
		ticketPrice = stod(strTicketPrice);
	} catch (...) {}
	unsigned int decimalIndex = strTicketPrice.find(".");
	std::size_t secondDecimal = strTicketPrice.find(".", decimalIndex + 1, 1);
	if (ticketPrice < 0 || ticketPrice > 999.99 || 
		(decimalIndex < strTicketPrice.length() && 
		strTicketPrice.length() - 1 - decimalIndex >= 3) || 
		secondDecimal < strTicketPrice.length()) {
		// Can only sell tickets for $0.00-999.99
		// and only with two digits of precision for cents value
		// and can only contain one decimal
		throw new TransactionException("Price of each ticket must be a number between $0.00-$999.99");
	}

	// Get user input for number of tickets to sell
	std::cout << "Enter number of tickets to sell: ";
	std::string strNumTickets;
	std::getline(std::cin, strNumTickets);

	// Convert user input to int
	int numTickets = -1;
	try {
		numTickets = stoi(strNumTickets);
	} catch (...) {}
	decimalIndex = strNumTickets.find(".");
	secondDecimal = strNumTickets.find(".", decimalIndex + 1, 1);
	if (numTickets <= 0 || numTickets > 100 || 
		(decimalIndex < strNumTickets.length() && 
		strNumTickets.length() - 1 - decimalIndex >= 1) || 
		secondDecimal < strNumTickets.length()) {
		// Can only sell 1-100 tickets
		throw new TransactionException("Number of tickets to sell must be a positive integer between 1-100");
	}

	// Transaction completed
	addTransaction(eventName, numTickets, ticketPrice);
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
