#include "BudgetManager.h"

// Constructor to initialize the BudgetManager with an initial budget and a TransactionManager
BudgetManager::BudgetManager(double initialBudget, TransactionManager transManager)
    : totalBudget(initialBudget), transactionManager(transManager) {}

// Find a budget by name
Budget& BudgetManager::findBudget(const std::string& name) {
    if (budgets.find(name) != budgets.end()) {
        return budgets[name];
    } else {
        throw std::runtime_error("Budget not found");
    }
}

// Create a new budget and add it to the budgets map
void BudgetManager::createBudget(const Budget& budget) {
    budgets[budget.getName()] = budget;
}

// Delete a budget by name
void BudgetManager::deleteBudget(const std::string& name) {
    if (budgets.find(name) != budgets.end()) {
        budgets.erase(name);
    } else {
        throw std::runtime_error("Budget not found");
    }
}

// Edit an existing budget
void BudgetManager::editBudget(const Budget& budget) {
    std::string name = budget.getName();
    if (budgets.find(name) != budgets.end()) {
        budgets[name] = budget;
    } else {
        throw std::runtime_error("Budget not found");
    }
}

// Calculate the remaining budget across all budgets
double BudgetManager::calculateRemainingBudget() const {
    double totalSpent = 0.0;
    for (const auto& pair : budgets) {
        totalSpent += pair.second.getTotalSpent();
    }
    return totalBudget - totalSpent;
}

// Calculate the remaining budget for a specific budget
double BudgetManager::calculateRemainingBudget(const Budget& budget) const {
    return budget.getTotalAmount() - budget.getTotalSpent();
}

// Display a summary of all budgets and their remaining amounts
void BudgetManager::displaySummary() const {
    std::cout << "Budget Summary:\n";
    for (const auto& pair : budgets) {
        if(pair.second.getTotalAmount() >= 0)
        {
            std::cout << "Budget Name: " << pair.first
                  << ", Total Amount: " << pair.second.getTotalAmount()
                  << ", Remaining Amount: " << (pair.second.getTotalAmount() - pair.second.getTotalSpent())
                  << std::endl;
        }
        else
        {
            std::cout << "Budget Name: " << pair.first
                  << ", Total Amount: " << pair.second.getTotalAmount()
                  << ", Over budget: " << abs(pair.second.getTotalAmount() - pair.second.getTotalSpent())
                  << std::endl;
        }
    }
}

// Get the total budget
double BudgetManager::getTotalBudget() const {
    return totalBudget;
}

// Set the total budget
void BudgetManager::setTotalBudget(double newBudget) {
    totalBudget = newBudget;
}

// Get all budgets as a map
std::unordered_map<std::string, Budget> BudgetManager::getAllBudgets() const {
    return budgets;
}

// Get the transaction manager
TransactionManager* BudgetManager::getTransactionManager() {
    return &transactionManager;
}
