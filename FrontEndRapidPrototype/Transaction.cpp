#include <string>
#include "Transaction.h"


Transaction::Transaction() {
	transactions = "";
}

/**
 * Returns whether a user is logged in or not
 *
 * @return True if a user is logged in, false otherwise.
 */
bool Transaction::isLoggedIn() {
	return (loggedInUser.getName().compare("") != 0);
}

/**
 * Return whether the logged-in user account 
 * is of the specified type
 *
 * @param type The account type
 * @return Whether the user account is the specified account type
 */
bool Transaction::isType(std::string type) {
	return (loggedInUser.getType().compare(type) == 0);
}

/**
 * Returns whether the logged-in user account
 * has the permission to purchase event tickets
 *
 * @return True if the user account can buy tickets, false otherwise.
 */
bool Transaction::canBuy() {
	return (isType("BS") || 
			isType("FS") || 
			isType("AA"));
}

/**
 * Returns whether the logged-in user account
 * has the permission to sell event tickets
 *
 * @return True if the user account can sell tickets, false otherwise.
 */
bool Transaction::canSell() {
	return (isType("SS") || 
			isType("FS") || 
			isType("AA"));
}

/**
 * Adds the transaction to the list of compelted
 * transactions to be written to the daily
 * transaction file
 *
 * @param transac The transaction to add
 */
void Transaction::addTransaction(std::string transac) {
	transactions += transac + "\n";
}
