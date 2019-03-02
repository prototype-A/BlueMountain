#include "UserManager.h"

static User getUser(std::string name){
    //Gets the user data from the file

    //Sets the user data to return
    User user;
    user.addCredit(999.99);
    user.setName("Test Name");
    Type type = AA;
    user.setType(type);
    return user;
};
static bool exists(std::string name){
    return true;
};