#include "Logout.h"
#include <iostream>
#include <fstream>
#include "User.h"

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
		loggedInUser = User();
		transactions = "";
	}
};

/*
* Goes through every entry made in the temporary
* transactions string and prints them into the
* daily transaction file.
*/
void Logout::writeToDailyFile() {
	//Writes to file
	std::ofstream dailyTransactionFile;
	dailyTransactionFile.open("dailytransactionfile.txt");
	dailyTransactionFile << transactions;
	dailyTransactionFile.close();
	
	//Exits the program (for testing purposes)
	exit(0);
}
