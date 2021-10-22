#pragma once
#include <string>

#include "Eigen/Dense"
#include "csv.hpp"

class ETL {
 public:
  ETL(std::string filename, bool no_header = false);
  ~ETL();
  void show();
  void load();
  Eigen::MatrixXd to_matrix();
  csv::CSVReader *reader_;
  std::vector<std::vector<double>> csv;
};
