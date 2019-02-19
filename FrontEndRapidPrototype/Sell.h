#include <string>
#include "Transaction.h"


class Sell : public Transaction {
public:
	void sellTickets();
private:
	void addTransaction(std::string eventName, int numTickets, double ticketPrice);
};
