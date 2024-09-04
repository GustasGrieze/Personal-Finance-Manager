#include "Transaction.h"
#include "Budget.h"
#include <iostream>
#include <algorithm>

int Transaction::nextId = 1;  // Initialize static member

Transaction::Transaction(const std::string& description, double amount, const std::string& date, Budget* budget)
    : id(nextId++), description(description), amount(amount), date(date), budget(budget) 
{
    if (budget != nullptr) {
        budget->addTransaction(this);
    }
}

int Transaction::getId() const { return id; }
std::string Transaction::getDescription() const { return description; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDate() const { return date; }

Budget& Transaction::getBudget() {
    return *(this->budget);
}

void Transaction::setDescription(const std::string& description) { this->description = description; }
void Transaction::setAmount(double amount) { this->amount = amount; }
void Transaction::setDate(const std::string& date) { this->date = date; }
void Transaction::setBudget(Budget* budget) { this->budget = budget; }

void TransactionManager::addTransaction(Transaction& transaction) {
    transactions.push_back(transaction);
}

bool TransactionManager::editTransaction(int id, const std::string& description, double amount, const std::string& date) {
    for (auto& transaction : transactions) {
        if (transaction.getId() == id) {
            transaction.setDescription(description);
            transaction.setAmount(amount);
            transaction.setDate(date);
            return true;
        }
    }
    return false;
}

bool TransactionManager::deleteTransaction(int id) {
    auto it = std::remove_if(transactions.begin(), transactions.end(), [id](const Transaction& transaction) { return transaction.getId() == id; });
    if (it != transactions.end()) {
        transactions.erase(it, transactions.end());
        return true;
    }
    return false;
}

void TransactionManager::viewTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << "ID: " << transaction.getId() 
                  << ", Description: " << transaction.getDescription()
                  << ", Amount: " << transaction.getAmount()
                  << ", Date: " << transaction.getDate() << std::endl;
    }
}

std::vector<Transaction> TransactionManager::getTransactions() const {
    return transactions;
}

std::vector<Transaction> TransactionManager::getExpenses() const {
    std::vector<Transaction> expenses;
    for (const Transaction& transaction : transactions) {
        if (transaction.getAmount() < 0) {
            expenses.push_back(transaction);
        }
    }
    return expenses;
}

std::vector<Transaction> TransactionManager::getIncomes() const {
    std::vector<Transaction> incomes;
    for (const Transaction& transaction : transactions) {
        if (transaction.getAmount() > 0) {
            incomes.push_back(transaction);
        }
    }
    return incomes;
}
