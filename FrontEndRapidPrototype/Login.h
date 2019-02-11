#include "Transaction.h"
#include <iostream>
class Login : public Transaction{
public:
	/*
	 * Displays prompts to allow a new user to
	 * login. This transaction can only be completed
	 * if there is no current user logged in and if the
	 * username exists within the users file.
	 */
	bool login() {
		if (Transaction::isLoggedIn()) {
			return false;
		}
		else {
			std::cout << "Please Enter a Username:	";
			std::string username;
			std::cin >> username;
			if (username.length > 15 | username.length < 1) {
				//TODO add other catches
				std::cout << "Username wrong length.";
				return false;
			}
			else {
				std::cout << "Login sucessful!";
			}
		}
	};
};