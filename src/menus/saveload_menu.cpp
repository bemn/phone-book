#include <iostream>

#include "cli/cli.h"
#include "menus.h"
#include "phone_book/phone_book.h"
#include "texts.h"

using phone_book::BookEntry;
using std::string;
using std::vector;

const string default_path = "book.csv";

void saveload_menu(vector<BookEntry>& book) {
  while (true) {
    const unsigned int action =
        cli::menu(saveload_menu_title, saveload_menu_desc, saveload_menu_items,
                  "Go back");

    if (action == 0) break;

    switch (action) {
      case 1: {  // Save
        string path = cli::read_line(string("Enter file path to save (") +
                                     default_path + ")");
        if (path.empty()) path = default_path;

        phone_book::save_to_csv(book, path);
        std::cout << "Saved to \"" << path << "\".\n";
        cli::wait_for_input();
        break;
      }

      case 2: {  // Load
        string path = cli::read_line(string("Enter file path to load (") +
                                     default_path + ")");
        if (path.empty()) path = default_path;

        auto loaded = phone_book::load_from_csv(path);
        if (loaded.empty()) {
          std::cout << "Couldn't read the file.\n";
        } else {
          book = loaded;
          std::cout << "Loaded from \"" << path << "\".\n";
        }

        cli::wait_for_input();
        break;
      }

      default:
        throw std::runtime_error("Unknown action");
    }
  }
}
