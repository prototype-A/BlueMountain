#include "UserManager.h"
#include <fstream>

static User getUser(std::string name){
    double credit;
    std::string filetype;
    std::string fileuname;

    //Gets the user data from the file
    std::string line;
    std::ifstream usersFile;
    usersFile.open("CurrentUsers.txt");
    if(usersFile.is_open()){
        while( std::getline(usersFile, line)){
            //Splits the data from the line
            fileuname = line.substr(0, 15);
            filetype = line.substr(16, 2);
            credit = std::stod(line.substr(19, 9));

            //Checks if its the right record
            if(name.compare(fileuname)==0){
                break;
            }
        }
        usersFile.close();
    }
    //Sets the user data to return
    User user;
    user.addCredit(credit);
    user.setName(fileuname);
    Type type = AA;
    user.setType(type);
    return user;
};
static bool exists(std::string name){
    //Gets the user data from the file
    std::string line;
    std::string fileuname;
    std::ifstream usersFile;
    usersFile.open("CurrentUsers.txt");
    if(usersFile.is_open()){
        while( std::getline(usersFile, line)){
            fileuname = line.substr(0, 15);
            //Checks if its the right record
            if(name.compare(fileuname)==0){
                return true;
            }
        }
        usersFile.close();
    }
    return false;
};