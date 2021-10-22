#include "etl.hpp"

int main() {
  ETL etl("data.csv", true);
  etl.load();
  etl.show();
  auto matrix = etl.to_matrix();
  std::cout << "Here's in matrix form:\n";
  std::cout << matrix << std::endl;
  return 0;
}
