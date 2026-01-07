#pragma once

#include <array>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::string;
using std::vector;

namespace cli {
inline void clear_terminal() {
  system("clear");  // TODO: make cross-platform
}

template <typename T>
std::optional<T> read_value(const string &msg) {
  std::cout << msg << ": " << std::flush;
  std::string line;
  std::getline(std::cin, line);
  if (line.empty()) {
    return std::nullopt;
  }
  std::stringstream stream(line);
  T value;
  if (stream >> value && stream.eof()) return value;
  return std::nullopt;
}

template <size_t N>
unsigned int menu(const string &title, const string &description,
                  const array<string, N> &items, const string &exit_message) {
  bool error = false;
  while (true) {
    clear_terminal();
    std::cout << " --- " << title << " --- \n";
    std::cout << description << "\n\n";
    for (int i = 0; i < items.size(); i++) {
      std::cout << i + 1 << ". " << items[i] << '\n';
    }
    std::cout << "\n0. " << exit_message << "\n\n";
    if (error) {
      std::cout << "Invalid input, try again." << std::endl;
    }
    if (const auto choice = read_value<unsigned int>("Enter your choice")) {
      if (*choice <= items.size()) {
        return *choice;
      }
    }
    error = true;
  }
}

inline void wait_for_input() {
  std::cout << "Press Enter to continue...\n";
  string throwaway;
  std::getline(std::cin, throwaway);
}

}  // namespace cli
