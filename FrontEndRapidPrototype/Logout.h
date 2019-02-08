#include "Transaction.h"
#include <iostream>
class Logout : public Transaction{
public:
	static void logout() {
		if (isLoggedIn()) {
			//Used to set the loggedInUser to NULL
			User *temp = &loggedInUser;
			temp = NULL;
		}
		else {
			std::cout << "ERROR: Not logged in";
		}
	};
};