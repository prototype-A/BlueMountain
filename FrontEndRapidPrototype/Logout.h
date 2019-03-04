#include <string>
#include "Transaction.h"


class Logout : public Transaction{
public:
	void logout();
	static void setDailyTransactionFileName(std::string filename);

private:
	inline static std::string dailyTransactionFileName;

	void writeToDailyFile();
};
