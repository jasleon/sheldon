#include "etl.hpp"

int main() {
  ETL etl("data.csv", true);
  etl.load();
  etl.show();
  return 0;
}
