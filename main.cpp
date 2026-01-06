#include <array>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "cli.h"

using std::array;
using std::string;
using std::vector;

int main() {
  std::cout << std::endl
            << cli::menu("Testing", array<string, 2>{"skibidi", "balls"},
                            "Leave");
}