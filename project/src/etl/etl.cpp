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

ETL::~ETL() { delete reader_; }

void ETL::show() {
  std::cout << "Here's the content of the dataset:\n";
  for (const auto& row : csv) {
    for (const auto& field : row) {
      std::cout << field << " ";
    }
    std::cout << '\n';
  }
  std::cout << "Number of rows: " << csv.size() << std::endl;
  std::cout << "Number of columns: " << csv[0].size() << std::endl;
}

void ETL::load() {
  std::cout << "Loading the dataset\n";
  for (auto& row : *reader_) {
    std::vector<double> values;
    for (auto& field : row) {
      values.push_back(field.get<double>());
    }
    csv.push_back(values);
  }
}

Eigen::MatrixXd ETL::to_matrix() {
  const size_t rows = csv.size();
  const size_t columns = csv[0].size();
  Eigen::MatrixXd matrix(rows, columns);
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      matrix(i, j) = csv[i][j];
    }
  }
  return matrix;
}
