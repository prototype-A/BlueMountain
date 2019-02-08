#include <string>
#include "User.h"
struct Type {

};
class Transaction{
public:
    static User loggedInUser;
    static std::string transactions;
 
    bool isLoggedIn();
    void addTransaction();
    void writeToDailyFile();
    void isType(Type type);
    bool canBuy();
    bool canSell();
};