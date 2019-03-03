#include "InputParser.h"
#include <iostream>


int main() {
    while (true) {
		// Get user input
        std::string input;
        std::cin >> input;
        
		// Parse user input
		InputParser::parseTransaction(input);
    }

    return 0;
}
