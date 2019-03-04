#pragma once
#include <string>


enum Type {
	AA,	// Admin
	BS,	// Buy Standard
	FS,	// Full Standard
	SS	// Sell Standard
};

class User {
public:
	User();
	User(std::string name, std::string type, double balance);

	void addCredit(double amount);
	void removeCredit(double amount);
	double getBalance();
	std::string getName();
	std::string getType();
	void setName(std::string n);
	void setType(Type t);
	static bool isValidType(std::string type);
private:
	std::string name;
	double credit;
	Type type;
};
