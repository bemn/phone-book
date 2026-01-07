#include <vector>

#include "cli/cli.h"
#include "menus/menus.h"
#include "phone_book/phone_book.h"
#include "texts.h"

int main() {
  std::vector<phone_book::BookEntry> book;

  while (true) {
    const unsigned int choice =
        cli::menu(main_menu_title, main_menu_desc, main_menu_items, "Quit");

    if (choice == 0) break;

    switch (choice) {
      case 1:
        query_menu(book);
        break;
      case 2:
        modify_menu(book);
        break;
      case 3:
        saveload_menu(book);
        break;
      default:
        throw std::runtime_error("Unknown choice");
    }
  }

  return 0;
}
