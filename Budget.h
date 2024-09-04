#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "Transaction.h"

class Budget {
private:
    std::string budgetName;
    double totalAmount;
    double presentAmount;
    std::vector<Transaction*> transactions;


public:
    void addTransaction(Transaction* transaction);
    void removeTransaction(int id);
    std::vector<Transaction*> getTransactions() const;
    std::string getName() const;
    double getTotalAmount() const;
    double getTotalSpent() const;
    void setTotalAmount(double amount);  // Added this method
    TransactionManager* getTransactionManager();

    Budget();
    Budget(std::string name, double amount);
    ~Budget();
};

#endif // BUDGET_H
