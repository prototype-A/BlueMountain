#include <fstream>
#include <iostream>

#include "Buy.h"
#include "InputParser.h"


void Buy::buyTickets() {
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
	// Ignore the newline from initiating transaction
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	std::getline(std::cin, eventName);
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
	std::string sellerName;
	// Ignore tprevious newline
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	std::getline(std::cin, sellerName);
	InputParser::parseIsValidUsername(sellerName);

	// Find tickets
	double ticketPrice = getTicketPrice(eventName, sellerName, numTickets);
	if (ticketPrice < 0) {
		throw new TransactionException("Event tickets not found");
	}

	// Transaction completed
	addTransaction(eventName, sellerName, numTickets, ticketPrice);
}

/*
 * Read from the available tickets file and get the unit price of
 * the ticket for the specified event name, sold by the specified
 * seller. Returns -1 if ticket was not found
 *
 * @param eventName The name of the event
 * @param sellerName The username of the ticket seller
 */
double Buy::getTicketPrice(std::string eventName, std::string sellerName,
						   int numTickets) {
	// Reads through available tickets file
	std::string line;
	std::ifstream ticketsFile;
	ticketsFile.open(availableTicketsFileName);
	if (ticketsFile.is_open()) {
		while (std::getline(ticketsFile, line)) {
			// Compare event name and seller name
			bool eventFound = eventName.compare(line.substr(0, 25)) == 0;
			bool sellerFound = sellerName.compare(line.substr(26, 15)) == 0;
			// Checks if ticket exists
			if (eventFound && sellerFound) {
				// Check if there are enough tickets
				int numTicketsForSale = std::stoi(line.substr(42, 3));
				if (numTicketsForSale < numTickets) {
					ticketsFile.close();
					throw new TransactionException("Sorry, there are not enough tickets left to fulfill this order");
				}
				double ticketPrice = std::stod(line.substr(46, 6));
				// Check if user has sufficient credit in their account
				// to make the purchase
				if (loggedInUser.getBalance() - (ticketPrice * numTickets) < 0) {
					ticketsFile.close();
					throw new TransactionException("You do not have sufficient credit on your account to complete this purchase");
				}

				ticketsFile.close();
				return ticketPrice;
			}
		}
		ticketsFile.close();
	}

	return -1;
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

/**
 * Called by the program's main() to set the available tickets
 * file name. Will default to "AvailableTickets.txt" if an
 * empty string is passed
 *
 * @param filename The name of the daily transaction file
 */
void Buy::setTicketsFileName(std::string filename) {
	if (filename.compare("") == 0) {
		availableTicketsFileName = "AvailableTickets.txt";
	} else {
		availableTicketsFileName = filename;
	}
}
