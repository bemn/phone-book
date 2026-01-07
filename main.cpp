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

// Main menu
const string main_menu_title = "Phone Book";
const string main_menu_desc =
    "You can search for entries with 'query',\n"
    "add, remove or edit them with 'modify,\n"
    "and save to or load the book from the file.";
const array<string, 3> main_menu_items{"Query", "Modify", "Save/Load"};

// Query menu
const string query_menu_title = "Phone Book | Query";
const string query_menu_desc =
    "Find entries by (partial) name, phone or email.\n"
    "Retrieved data will be sorted alphabetically by name.";
const array<string, 3> query_menu_items{"Find by name", "Find by phone",
                                        "Find by email"};

// Modify menu
const string modify_menu_title = "Phone Book | Modify";
const string modify_menu_desc =
    "Add new entries with 'add', remove with 'remove',\n"
    "edit them with 'edit'.";
const array<string, 3> modify_menu_items{"Add", "Remove", "Edit"};

// Save/Load menu
const string saveload_menu_title = "Phone Book | Save/Load";
const string saveload_menu_desc =
    "Save current book to a specified file with 'save to',\n"
    "or load from a file with 'load from'.";
const array<string, 2> saveload_menu_items{"Save to", "Load from"};

void query_menu() {
  while (true) {
    const unsigned int action = cli::menu(query_menu_title, query_menu_desc,
                                          query_menu_items, "Go back");
    if (action == 0) {
      break;
    }
  }
}

void modify_menu() {
  while (true) {
    const unsigned int action = cli::menu(modify_menu_title, modify_menu_desc,
                                          modify_menu_items, "Go back");
    if (action == 0) {
      break;
    }
  }
}

void saveload_menu() {
  while (true) {
    const unsigned int action =
        cli::menu(saveload_menu_title, saveload_menu_desc, saveload_menu_items,
                  "Go back");
    if (action == 0) {
      break;
    }
  }
}

int main() {
  while (true) {
    // Display main menu
    const unsigned int choice =
        cli::menu(main_menu_title, main_menu_desc, main_menu_items, "Quit");
    if (choice == 0) {
      break;
    }

    // Now go over each menu
    switch (choice) {
      default:
        throw std::runtime_error("Unknown choice");
      case 1:
        query_menu();
        break;
      case 2:
        modify_menu();
        break;
      case 3:
        saveload_menu();
        break;
    }
  }
  return 0;
}