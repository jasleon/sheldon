#include "etl.hpp"
#include <iostream>

ETL::ETL(std::string filename) : filename_(filename) {
    std::cout << filename_ << std::endl;
}

