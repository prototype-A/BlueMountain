#include <string>


class InputParser {
public:
	static void parseTransaction(std::string transac);
	static std::string parseTransacTickets(int numTickets);
	static std::string parseTransacTicketPrice(double price);
	static std::string parseTransacAmount(double amount);
	static std::string parseTransacName(std::string name);
	static std::string parseTransacEventName(std::string name);
private:
	static std::string padNumAmount(int amount, int len);
	static std::string padNumAmount(double amount, int len);
	static std::string padString(std::string str, int len);
};
