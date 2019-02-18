#include "Transaction.h"


class AddCredit : public Transaction {
public:
	double sessionCreditLimit = 1000.00;

	void addCredit();
	void addCredit(User user, double amount);
};
