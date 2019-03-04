#include <string>
#include "Transaction.h"


class Buy : public Transaction {
public:
	void buyTickets();
	static void setTicketsFileName(std::string filename);
private:
	inline static std::string availableTicketsFileName;

	double getTicketPrice(std::string eventName, std::string sellerName, int numTickets);
	void addTransaction(std::string eventName, std::string sellerName, int numTickets, double ticketPrice);
};
