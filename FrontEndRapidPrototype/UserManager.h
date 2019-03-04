#include <string>
#include "User.h"


class UserManager {
public:
    static User getUser(std::string name);
    static bool exists(std::string name);
	static void setAccountsFileName(std::string filename);
private:
	inline static std::string accountsFileName;
};
