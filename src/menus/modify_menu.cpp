#include <iostream>

#include "cli/cli.h"
#include "menus.h"
#include "texts.h"

using phone_book::BookEntry;
using std::string;
using std::vector;

void modify_menu(vector<BookEntry>& book) {
  while (true) {
    const unsigned int action = cli::menu(modify_menu_title, modify_menu_desc,
                                          modify_menu_items, "Go back");

    if (action == 0) break;
  }
}