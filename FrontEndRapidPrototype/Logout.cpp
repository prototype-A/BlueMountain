#include "Logout.h"
#include <iostream>

/*
* Checks to make sure a logout can take
* place and then readies the daily transaction
* file for creation.
*/
void Logout::logout() {
	if (Transaction::isLoggedIn()) {
		//Used to set the loggedInUser to NULL
		User *temp = &loggedInUser;
		temp = NULL;
		writeToDailyFile();
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
void Logout::writeToDailyFile() {

}