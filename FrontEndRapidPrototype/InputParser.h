#include <string>


class InputParser {
public:
	static void parseTransaction(std::string transac);
	static std::string parseTransacAmount(double amount);
	static std::string parseTransacName(std::string name);
};
