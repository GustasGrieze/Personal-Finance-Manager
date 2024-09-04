#include "report_generator.h"

ReportGenerator::ReportGenerator(TransactionManager& manager) : manager(manager) {}

void ReportGenerator::generateSummaryReport() const {
    std::cout << "\n Transaction Summary Report\n";
    std::cout << "--------------------------\n";

    double totalAmount = 0.0;
    for (const auto& transaction : manager.getTransactions()) {
        totalAmount += transaction.getAmount();
    }

    std::cout << "Total Transactions: " << manager.getTransactions().size() << "\n";
    std::cout << "Total Amount: $" << totalAmount << "\n\n";
    
    manager.viewTransactions();  // Show all transactions as part of the report
}
