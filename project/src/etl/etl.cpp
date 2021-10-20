#include "etl.hpp"
#include <iostream>

ETL::ETL(std::string filename) : reader_(filename) {
    std::cout << "ETL says hello!\n";
}

void ETL::show() {
    std::cout << "Here's the content of the dataset:\n";
    for (auto& row : reader_) {
        for (auto& field : row) {
            std::cout << field.get<>() << " ";
        }
        std::cout << '\n';
    }
}
