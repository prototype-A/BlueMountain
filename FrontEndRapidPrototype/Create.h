#include "Transaction.h"

class Create : public Transaction{
public:
	void create();

private:
	void addTransaction(User username, Type type, double balance);
};