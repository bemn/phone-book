#include <iostream>

#include "cli/cli.h"
#include "menus.h"
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
        for (size_t i = 0; i < book.size(); ++i) {
          std::cout << i + 1 << ". " << phone_book::to_string(book[i]) << '\n';
        }
      }
      cli::wait_for_input();
      continue;
    }

    phone_book::BookField field = {};
    string query;

    while (query.empty()) {
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

      if (auto q = cli::read_value<string>("Enter query")) {
        query = *q;
      }
    }

    if (auto result = phone_book::find_by(book, field, query); result.empty()) {
      std::cout << "There are no entries for this query.\n";
    } else {
      std::cout << "Found entries:\n";
      for (const auto index : result) {
        std::cout << index + 1 << ". " << phone_book::to_string(book[index])
                  << '\n';
      }
    }

    cli::wait_for_input();
  }
}
