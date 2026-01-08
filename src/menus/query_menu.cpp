#include <iostream>

#include "cli/cli.h"
#include "menus.h"
#include "phone_book/phone_book.h"
#include "texts.h"

using phone_book::BookEntry;
using std::string;
using std::vector;

void query_menu(const vector<BookEntry>& book) {
  while (true) {
    const unsigned int action = cli::menu(query_menu_title, query_menu_desc,
                                          query_menu_items, "Go back");

    if (action == 0) break;

    if (action == 4) {
      if (book.empty()) {
        std::cout << "There are no entries.\n";
      } else {
        std::cout << "All entries:\n";
        auto table = phone_book::to_table(book);
        for (const auto& line : table) {
          std::cout << line << '\n';
        }
      }
      cli::wait_for_input();
      continue;
    }

    phone_book::BookField field = {};
    switch (action) {
      case 1:
        field = phone_book::NAME;
        break;
      case 2:
        field = phone_book::PHONE;
        break;
      case 3:
        field = phone_book::EMAIL;
        break;
      default:
        throw std::runtime_error("Unknown action");
    }

    string query = cli::read_line("Enter query");
    auto result = phone_book::find_by(book, field, query);
    if (result.empty() || query.empty()) {
      std::cout << "There are no entries for this query.\n";
    } else {
      std::cout << "Found entries:\n";
      vector<string> table(1);
      for (unsigned long i : result) {
        auto row = phone_book::to_table(book, i, 1);
        table[0] = row[0];
        table.push_back(row[1]);
      }
      for (const auto& line : table) {
        std::cout << line << '\n';
      }
    }

    cli::wait_for_input();
  }
}
