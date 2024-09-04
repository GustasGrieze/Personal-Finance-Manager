#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include "Transaction.h"
#include <vector>
#include <iostream>

class ReportGenerator {
public:
    explicit ReportGenerator(TransactionManager& manager);
    void generateSummaryReport() const;

private:
    const TransactionManager& manager;
};

#endif // REPORT_GENERATOR_H
