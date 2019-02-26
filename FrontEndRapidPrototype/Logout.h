#include "Transaction.h"

class Logout : public Transaction{
public:
	void logout();
private:
	void writeToDailyFile();
};