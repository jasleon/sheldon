#include <iostream>
#include "csv.hpp"
using namespace csv;

int main() {
    CSVReader reader("data.csv");
    for (auto& row : reader) {
        for (auto& field : row) {
            std::cout << field.get<>() << std::endl;
        }
    }
}
