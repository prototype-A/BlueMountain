#include "Transaction.h"


class AddCredit : public Transaction {
public:
	inline static double sessionCreditLimit = 1000.00;

	void addCredit();
	void addCredit(User user, double amount);
};
