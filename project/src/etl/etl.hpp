#pragma once
#include <string>
#include "csv.hpp"

class ETL {
    public:
        ETL(std::string filename);
        void show();
        csv::CSVReader reader_;
};
