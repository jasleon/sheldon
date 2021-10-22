#include "etl.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "usage: helloEtl path-to-csv\n";
    return -1;
  }
  std::string path(argv[1]);
  ETL etl(path, true);
  etl.load();
  etl.show();
  auto matrix = etl.to_matrix();
  std::cout << "Here's in matrix form:\n";
  std::cout << matrix << std::endl;
  return 0;
}
