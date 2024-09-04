#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
#include <string>

class Budget;
class BudgetManager;

class Transaction {
private:
    static int nextId;
    int id;
    std::string description;
    double amount;
    std::string date;
    Budget* budget;

public:
    Transaction(const std::string& description, double amount, const std::string& date, Budget* budget);
    int getId() const;
    std::string getDescription() const;
    double getAmount() const;
    std::string getDate() const;
    Budget& getBudget();
    void setDescription(const std::string& description);
    void setAmount(double amount);
    void setDate(const std::string& date);
    void setBudget(Budget* budget);
};

class TransactionManager {
public:
    void addTransaction(Transaction& transaction);
    bool editTransaction(int id, const std::string& description, double amount, const std::string& date);
    bool deleteTransaction(int id);
    void viewTransactions() const;
    std::vector<Transaction> getTransactions() const;
    std::vector<Transaction> getExpenses() const;
    std::vector<Transaction> getIncomes() const;
    BudgetManager* budgetManager;

private:
    std::vector<Transaction> transactions;
};

#endif // TRANSACTIONS_H
