#include "etl.hpp"

#include <sciplot/sciplot.hpp>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "usage: helloEtl path-to-csv\n";
    return -1;
  }
  std::string path(argv[1]);
  ETL etl(path, true);
  etl.load();

  // Convert CSV to Matrix
  auto matrix = etl.to_matrix();
  auto x = matrix.col(0);
  auto y = matrix.col(1);

  // Create a Plot object
  sciplot::Plot plot;

  // Set color palette
  plot.palette("set2");

  // Set the legend
  plot.legend().hide();

  // Set the x and y labels
  plot.xlabel("Population of City in 10,000s");
  plot.ylabel("Profit in $10,000s");

  // Draw a scatter plot to visualize the data
  plot.drawPoints(x, y).pointType(2);

  // Show the plot in a pop-up window
  plot.show();

  return 0;
}
