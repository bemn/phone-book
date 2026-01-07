#include <array>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "cli.h"
#include "phone_book.h"

using phone_book::BookEntry;
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

void query_menu(const vector<BookEntry>& book) {
  while (true) {
    const unsigned int action = cli::menu(query_menu_title, query_menu_desc,
                                          query_menu_items, "Go back");
    if (action == 0) {
      break;
    }

    phone_book::BookField field = {};
    string query;
    while (query.empty()) {
      switch (action) {
        default:
          throw std::runtime_error("Unknown action");
        case 1:
          field = phone_book::NAME;
          if (auto q = cli::read_value<string>("Enter name query")) {
            query = *q;
          }
          break;
        case 2:
          field = phone_book::PHONE;
          if (auto q = cli::read_value<string>("Enter phone query")) {
            query = *q;
          }
          break;
        case 3:
          field = phone_book::EMAIL;
          if (auto q = cli::read_value<string>("Enter email query")) {
            query = *q;
          }
          break;
      }
    }

    auto result = phone_book::find_by(book, field, query);
    if (!result.empty()) {
      std::cout << "Found entries:\n";
    } else {
      std::cout << "There are no entries for this query.\n";
    }
    for (const size_t& index : result) {
      std::cout << index + 1 << ". " << phone_book::to_string(book[index])
                << '\n';
    }

    cli::wait_for_input();
  }
}

void modify_menu(const vector<BookEntry>& book) {
  while (true) {
    const unsigned int action = cli::menu(modify_menu_title, modify_menu_desc,
                                          modify_menu_items, "Go back");
    if (action == 0) {
      break;
    }
  }
}

void saveload_menu(const vector<BookEntry>& book) {
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
  auto book = vector<BookEntry>();
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
        query_menu(book);
        break;
      case 2:
        modify_menu(book);
        break;
      case 3:
        saveload_menu(book);
        break;
    }
  }
  return 0;
}