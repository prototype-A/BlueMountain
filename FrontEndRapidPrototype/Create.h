#include "Transaction.h"

class Create : public Transaction{
public:
	bool create();

private:
	void addTransaction(User username, Type type, double balance);
};