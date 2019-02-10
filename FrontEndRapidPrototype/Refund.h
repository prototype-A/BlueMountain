#include "Transaction.h"


class Refund : public Transaction {
public:
	void refund();
private:
	void addTransaction(User buyer, User seller, double amount);
	void refund(User user1, User user2, double amount);
};
