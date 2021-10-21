#pragma once
#include <string>
#include "csv.hpp"

class ETL {
    public:
        ETL(std::string filename, bool no_header = false);
        ~ETL();
        void show();
        csv::CSVReader *reader_;
};
