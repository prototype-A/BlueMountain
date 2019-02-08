#include <iostream>
#include <string>
#include "Login.h"
#include "Transaction.h"

int main(){
    while(true){
        std::string input;
        std::cin >> input;
		if (input.compare("login") == 0) {
			if (Login::login()) {
				std::cout << "login" << std::endl;
			}
		}
		else if (input.compare("logout") == 0) {
			std::cout << "logout" << std::endl;
		}
		else if (input.compare("create") == 0) {
			std::cout << "create" << std::endl;
		}
		else if (input.compare("delete") == 0) {
			std::cout << "delete" << std::endl;
		}
		else if (input.compare("buy") == 0) {
			std::cout << "buy" << std::endl;
		}
		else if (input.compare("addcredit") == 0) {
			std::cout << "addcredit" << std::endl;
		}
		else if (input.compare("refund") == 0) {
			std::cout << "refund" << std::endl;
		}
		else if (input.compare("sell") == 0) {
			std::cout << "sell" << std::endl;
		}
		else {
			std::cout << "Invalid transaction try again!" << std::endl;
		}
    }
    return 0;
}