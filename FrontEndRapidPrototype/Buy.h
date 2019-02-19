#include <string>
#include "Transaction.h"


class Buy : public Transaction {
public:
	void buyTickets();
private:
	void addTransaction(std::string eventName, std::string sellerName, int numTickets, double ticketPrice);
};
