#pragma once
#include <string>

#include "csv.hpp"

class ETL {
 public:
  ETL(std::string filename, bool no_header = false);
  ~ETL();
  void show();
  void load();
  csv::CSVReader *reader_;
  std::vector<std::vector<double>> csv;
};
