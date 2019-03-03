#include "Logout.h"
#include <iostream>

/*
* Checks to make sure a logout can take
* place and then readies the daily transaction
* file for creation.
*/
void Logout::logout() {
    //Check if the user is logged
    if(!Transaction::isLoggedIn()){
        throw new TransactionException("Not logged in.");
    }else{
		//Used to set the loggedInUser to NULL
		User *temp = &loggedInUser;
		temp = NULL;
		writeToDailyFile();
	}
};

/*
* Goes through every entry made in the temporary
* transactions string and prints them into the
* daily transaction file.
*/
void Logout::writeToDailyFile() {
	//Writes to file

	//Exits the program (for testing purposes)
	exit(0);
}