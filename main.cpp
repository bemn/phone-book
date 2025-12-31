#include <iostream>
#include <string>

int main() {
  // главный цикл
  bool enabled = true;
  do {
    std::string line;
    std::getline(std::cin, line);
    if (line.empty()) {
      std::cout << "TODO: empty string warning" << std::endl;
      continue;
    }
  } while (enabled);
  return 0;
}