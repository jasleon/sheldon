#include "etl.hpp"
#include <iostream>

ETL::ETL(std::string filename, bool no_header) : reader_(nullptr) {
    std::cout << "ETL says hello!\n";
    csv::CSVFormat format;
    if (no_header) {
        format.no_header();
    }
    reader_ = new csv::CSVReader(filename, format);
}

ETL::~ETL() {
    delete reader_;
}

void ETL::show() {
    std::cout << "Here's the content of the dataset:\n";
    for (auto& row : *reader_) {
        for (auto& field : row) {
            std::cout << field.get<>() << " ";
        }
        std::cout << '\n';
    }
}
