#include "Budget.h"

// Default constructor
Budget::Budget() : budgetName(""), totalAmount(0), presentAmount(0) {}

// Parameterized constructor
Budget::Budget(std::string name, double amount) : budgetName(name), totalAmount(amount), presentAmount(amount) {}

// Destructor
Budget::~Budget() {
    // Free allocated memory for transactions
    for (Transaction* transaction : transactions) {
        delete transaction;
    }
}

// Add a transaction to the budget
void Budget::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
    presentAmount += transaction->getAmount();  // Update present amount
}

// Remove a transaction from the budget by ID
void Budget::removeTransaction(int id) {
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        if ((*it)->getId() == id) {  // Dereference the iterator to get the Transaction object
            presentAmount -= (*it)->getAmount();  // Update present amount
            delete *it;  // Free the allocated memory for the Transaction
            transactions.erase(it);
            break;
        }
    }
}

// Get all transactions
std::vector<Transaction*> Budget::getTransactions() const {
    return transactions;
}

// Get the name of the budget
std::string Budget::getName() const {
    return budgetName;
}

// Get the total amount of the budget
double Budget::getTotalAmount() const {
    return totalAmount;
}

// Calculate the total amount spent
double Budget::getTotalSpent() const {
    double totalSpent = 0.0;
    for (const auto& transaction : transactions) {
        if (transaction->getAmount() < 0) {  // Consider only expenses
            totalSpent += transaction->getAmount();
        }
    }
    return -totalSpent;  // Return positive value of total spent
}

// Set the total amount of the budget
void Budget::setTotalAmount(double amount) {
    totalAmount = amount;
}

// // Get the transaction manager
// TransactionManager* Budget::getTransactionManager() {
//     return &transactionManager;
// }
