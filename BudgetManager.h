#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Transaction.h"
#include "Budget.h"

class BudgetManager {
private:
    double totalBudget;
    std::unordered_map<std::string, Budget> budgets;
    TransactionManager transactionManager;

public:
    BudgetManager(double initialBudget, TransactionManager transManager);

    Budget& findBudget(const std::string& name);
    void createBudget(const Budget& budget);
    void deleteBudget(const std::string& name);
    void editBudget(const Budget& budget);

    double calculateRemainingBudget() const;
    double calculateRemainingBudget(const Budget& budget) const;
    void displaySummary() const;

    double getTotalBudget() const;  // Keep only one declaration
    void setTotalBudget(double newBudget);
    std::unordered_map<std::string, Budget> getAllBudgets() const;
    TransactionManager* getTransactionManager();
};

#endif // BUDGETMANAGER_H
