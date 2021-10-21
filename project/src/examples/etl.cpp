#include <etl.hpp>

int main() {
    ETL etl("data.csv", true);
    etl.show();
    return 0;
}
