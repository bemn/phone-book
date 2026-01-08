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
#ifdef _WIN32
  std::system("cls");
#else
  std::cout << "\033[2J\033[H" << std::flush;
#endif
}

inline string trim(const string &str) {
  auto start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    ++start;
  }

  auto end = str.end();
  do {
    --end;
  } while (end != start && std::isspace(*end));

  if (start > end) {
    return "";
  }

  return {start, end + 1};
}

template <typename T>
std::optional<T> read_value(const string &msg) {
  std::cout << msg << ": " << std::flush;
  string line;
  std::getline(std::cin, line);
  if (line.empty()) {
    return std::nullopt;
  }
  line = trim(line);
  std::stringstream stream(line);
  T value;
  if (stream >> value && stream.eof()) return value;
  return std::nullopt;
}

inline string read_line(const string &msg) {
  std::cout << msg << ": " << std::flush;
  string line;
  std::getline(std::cin, line);
  line = trim(line);
  string sanitized;
  for (const char &c : line) {
    if (std::isprint(c) && c != ',') {
      sanitized += c;
    }
  }

  return sanitized;
}

template <size_t N>
unsigned int menu(const string &title, const string &description,
                  const array<string, N> &items, const string &exit_message) {
  bool error = false;
  while (true) {
    clear_terminal();
    std::cout << " --- " << title << " --- \n";
    std::cout << description << "\n\n";
    for (size_t i = 0; i < items.size(); i++) {
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
