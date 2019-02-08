#include "Transaction.h"
#include <iostream>
class Login : public Transaction{
public:
	static bool login() {
		if (isLoggedIn()) {
			return false;
		}
		else {
			std::cout << "Please Enter a Username:	";
			std::string username;
			std::cin >> username;
			if (username.length > 15 | username.length < 1) {
				//TODO add other catches
				return false;
			}
			else {
				std::cout << "Login sucessful!";
			}
		}
	};
};