#include <string>



enum Type {
	AA,	// Admin
	BS,	// Buy Standard
	FS,	// Full Standard
	SS	// Sell Standard
};

class User {
public:
	void addCredit(double amount);
	void removeCredit(double amount);
	double getBalance();
	std::string getName();
	std::string getType();
private:
	std::string name;
	double credit;
	Type type;
};
