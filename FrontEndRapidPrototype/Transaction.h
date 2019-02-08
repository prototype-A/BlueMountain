#include <string>
#include "User.h"
struct Type {

};
class Transaction{
public:
    static User loggedInUser;
    static std::string transactions;

    static bool isLoggedIn();
    void addTransaction();
    void writeToDailyFile();
    void isType(Type type);
    bool canBuy();
    bool canSell();
};