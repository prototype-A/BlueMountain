#pragma once
#include <exception>


class TransactionException : public std::exception {
public:
	TransactionException(const char* errMsg) { this->errMsg = errMsg; }

	virtual const char* what() {
		return this->errMsg;
	}
private:
	const char* errMsg;
};
