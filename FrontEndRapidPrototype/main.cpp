#include <iostream>

#include "Buy.h"
#include "InputParser.h"
#include "Logout.h"
#include "UserManager.h"


int main(int argc, char** argv) {

	// Default filenames
	std::string accountsFileName;
	std::string ticketsFileName;
	std::string dailyTransactionFileName;

	// Get command-line input, if any, for custom file names
	if (argc > 1) {
		try {
			accountsFileName = argv[1];
			ticketsFileName = argv[2];
			dailyTransactionFileName = argv[3];
		} catch (...) {}
	}

	// Set file names in their required classes
	Buy::setTicketsFileName(ticketsFileName);
	UserManager::setAccountsFileName(accountsFileName);
	Logout::setDailyTransactionFileName(dailyTransactionFileName);

    while (true) {
		// Get user input
        std::string input;
        std::getline(std::cin, input);
        
		// Parse user input
		InputParser::parseTransaction(input);
    }

    return 0;
}
