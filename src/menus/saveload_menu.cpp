#include <iostream>

#include "cli/cli.h"
#include "menus.h"
#include "texts.h"

using phone_book::BookEntry;
using std::string;
using std::vector;

void saveload_menu(vector<BookEntry>& book) {
  while (true) {
    const unsigned int action =
        cli::menu(saveload_menu_title, saveload_menu_desc, saveload_menu_items,
                  "Go back");

    if (action == 0) break;
  }
}