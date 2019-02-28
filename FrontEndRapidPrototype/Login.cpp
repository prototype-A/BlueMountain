#include "Login.h"
#include <iostream>
#include "UserManager.h"
/*
 * Displays prompts to allow a new user to
 * login. This transaction can only be completed
 * if there is no current user logged in and if the
 * username exists within the users file.
 */
void Login::login() {
	if (Transaction::isLoggedIn()) {
		throw new TransactionException("Logged In");
	}
	else {
		std::cout << "Please Enter a Username:	";
		std::string username;
		std::cin >> username;
        if(!UserManager::exists(username)){
            throw new TransactionException("User does not exist!");
        }
		if (username.length() > 15 | username.length() < 1) {
			//TODO add other catches
			throw new TransactionException("Username wrong length.");
		}
		else {
			loggedInUser = UserManager::getUser(username);
			throw new TransactionException("Login sucessful!");
		}
	}
};