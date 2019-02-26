#include "Transaction.h"

class Delete : public Transaction{
public:
	void deleteUser();
private:
	void addTransaction(User user);
};