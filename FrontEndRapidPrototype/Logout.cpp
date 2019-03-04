#include <fstream>
#include <iostream>

#include "AddCredit.h"
#include "InputParser.h"
#include "Logout.h"
#include "User.h"

/*
* Checks to make sure a logout can take
* place and then readies the daily transaction
* file for creation.
*/
void Logout::logout() {
    //Check if the user is logged
    if (!Transaction::isLoggedIn()) {
        throw new TransactionException("Not logged in.");
    } else {
		// Add completed transaction to list for current session
		Transaction::addTransaction("00 " + 
			InputParser::parseTransacName(loggedInUser.getName()) + " " + 
			loggedInUser.getType() + " " + 
			InputParser::parseTransacAmount(loggedInUser.getBalance()));

		std::cout << "Logged out" << std::endl;

		// Write to the daily file
		writeToDailyFile();

		// Reset values
		loggedInUser = User();
		transactions = "";
		AddCredit::sessionCreditLimit = 1000.00;
	}
}

/*
* Goes through every entry made in the temporary
* transactions string and prints them into the
* daily transaction file.
*/
void Logout::writeToDailyFile() {
	//Writes to file
	std::ofstream dailyTransactionFile;
	dailyTransactionFile.open(dailyTransactionFileName);
	dailyTransactionFile << transactions;
	dailyTransactionFile.flush();
	dailyTransactionFile.close();
	
	//Exits the program (for testing purposes)
	exit(0);
}

/**
 * Called by the program's main() to set the daily transaction
 * file name. Will default to "transout.atf" if an empty string
 * is passed
 *
 * @param filename The name of the daily transaction file
 */
void Logout::setDailyTransactionFileName(std::string filename) {
	if (filename.compare("") == 0) {
		dailyTransactionFileName = "transout.atf";
	} else {
		dailyTransactionFileName = filename;
	}
}
