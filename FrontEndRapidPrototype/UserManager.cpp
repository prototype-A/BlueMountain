#include <fstream>
#include <iostream>

#include "InputParser.h"
#include "UserManager.h"


User UserManager::getUser(std::string name) {
	std::string username;
    std::string userType;
    double userBalance;

    //Gets the user data from the file
    std::string line;
    std::ifstream usersFile;
    usersFile.open(accountsFileName);
    if (usersFile.is_open()){
        while (std::getline(usersFile, line)) {
            //Splits the data from the line
            username = InputParser::trim(line.substr(0, 15));
            userType = line.substr(16, 2);
            userBalance = std::stod(line.substr(19, 9));
            
            //Checks if its the right record
            if (name.compare(username) == 0) {
                break;
            }
        }
        usersFile.close();
    }

	User user(username, userType, userBalance);

    return user;
}

bool UserManager::exists(std::string name) {
    //Gets the user data from the file
    std::string username;
    std::string line;
    std::ifstream usersFile;
    usersFile.open(accountsFileName);
    if (usersFile.is_open()) {
        while (std::getline(usersFile, line)) {
            username = InputParser::trim(line.substr(0, 15));
            //Checks if its the right record
            if (name.compare(username) == 0) {
                return true;
            }
        }
        usersFile.close();
    }

    return false;
}

/**
 * Called by the program's main() to set the current users
 * file name. Will default to "CurrentUsers.txt" if an
 * empty string is passed
 *
 * @param filename The name of the daily transaction file
 */
void UserManager::setAccountsFileName(std::string filename) {
	if (filename.compare("") == 0) {
		accountsFileName = "CurrentUsers.txt";
	} else {
        std::cout << filename;
		accountsFileName = filename;
	}
}
