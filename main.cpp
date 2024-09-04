#include <iostream>
#include "Budget.h"
#include "BudgetManager.h"
#include "Transaction.h"
#include "report_generator.h"
#include <limits>

void displayMenu() {
    std::cout << "1. Create Budget\n";
    std::cout << "2. Add Transaction\n";
    std::cout << "3. View Budgets\n";
    std::cout << "4. Generate Report\n";
    std::cout << "5. Delete Budget\n";
    std::cout << "6. Edit Budget\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void createBudget(BudgetManager *budgetManager) {
    std::string name;
    double amount;
    std::cout << "Enter budget name: ";
    std::cin >> name;
    std::cout << "Enter total amount: ";
    std::cin >> amount;
    Budget newBudget(name, amount);
    budgetManager->createBudget(newBudget);
    std::cout << "Budget created successfully.\n";
}

void addTransaction(BudgetManager *budgetManager) {
    std::string budgetName, description, date;
    double amount;
    std::cout << "Enter budget name: ";
    std::cin >> budgetName;
    std::cout << "Enter transaction description: ";
    std::cin >> description;
    std::cout << "Enter transaction amount: ";
    std::cin >> amount;
    std::cout << "Enter transaction date (YYYY-MM-DD): ";
    std::cin >> date;

    try {
        Budget& budget = budgetManager->findBudget(budgetName);
        Transaction *transaction = new Transaction(description, amount, date, &budget);
        budgetManager->getTransactionManager()->addTransaction(*transaction);
        // budget.addTransaction(transaction);
        std::cout << "Transaction added successfully.\n";
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }
}

void viewBudgets(const BudgetManager *budgetManager) {
    budgetManager->displaySummary();
}

void generateReport(BudgetManager *budgetManager) {
    if (!budgetManager->getAllBudgets().empty()) {
        ReportGenerator reportGenerator((*budgetManager->getTransactionManager()));
        reportGenerator.generateSummaryReport();
    } else {
        std::cout << "No budgets available to generate a report.\n";
    }
}

void deleteBudget(BudgetManager *budgetManager) {
    std::string name;
    std::cout << "Enter budget name to delete: ";
    std::cin >> name;

    try {
        budgetManager->deleteBudget(name);
        std::cout << "Budget deleted successfully.\n";
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }
}

void editBudget(BudgetManager *budgetManager) {
    std::string name;
    double newAmount;
    std::cout << "Enter budget name to edit: ";
    std::cin >> name;

    try {
        Budget& budget = budgetManager->findBudget(name);
        std::cout << "Enter new total amount: ";
        std::cin >> newAmount;
        budget.setTotalAmount(newAmount);
        budgetManager->editBudget(budget);
        std::cout << "Budget edited successfully.\n";
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << '\n';
    }
}

int main() {
    TransactionManager transactionManager;
    BudgetManager budgetManager(1000.0, transactionManager);
    int choice;

    while (true) {
        std::cout<<"\n";
        displayMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                createBudget(&budgetManager);
                break;
            case 2:
                addTransaction(&budgetManager);
                break;
            case 3:
                viewBudgets(&budgetManager);
                break;
            case 4:
                generateReport(&budgetManager);
                break;
            case 5:
                deleteBudget(&budgetManager);
                break;
            case 6:
                editBudget(&budgetManager);
                break;
            case 7:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
