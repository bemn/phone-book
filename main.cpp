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
  while (true) {
    const string main_menu_desc =
        "You can search for entries with 'query',\n"
        "add, remove or edit them with 'modify,\n"
        "and save to or load the book from the file.";
    const array<string, 3> main_menu_items{"Query", "Modify", "Save/Load"};
    unsigned int choice =
        cli::menu("Phone Book", main_menu_desc, main_menu_items, "Quit");
    if (choice == 0) {
      return 0;
    }
  }
}