#include "Transaction.h"
#include <iostream>
class Logout : public Transaction{
public:
	/*
	* Checks to make sure a logout can take
	* place and then readies the daily transaction
	* file for creation.
	*/
	void logout() {
		if (Transaction::isLoggedIn()) {
			//Used to set the loggedInUser to NULL
			User *temp = &loggedInUser;
			temp = NULL;
			writeDailyTFile();
		}
		else {
			std::cout << "ERROR: Not logged in";
		}
	};
	/*
	* Goes through every entry made in the temporary
	* transactions string and prints them into the
	* daily transaction file.
	*/
	void writeDailyTFile() {

	}
};