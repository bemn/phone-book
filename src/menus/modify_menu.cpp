#include <iostream>

#include "cli/cli.h"
#include "menus.h"
#include "texts.h"

using phone_book::BookEntry;
using std::string;
using std::vector;

void add_submenu(vector<BookEntry>& book);
void remove_submenu(vector<BookEntry>& book);
void edit_submenu(vector<BookEntry>& book);

void modify_menu(vector<BookEntry>& book) {
  while (true) {
    const unsigned int action = cli::menu(modify_menu_title, modify_menu_desc,
                                          modify_menu_items, "Go back");

    if (action == 0) break;

    switch (action) {
      case 1:
        add_submenu(book);
        break;
      case 2:
        remove_submenu(book);
        break;
      case 3:
        edit_submenu(book);
        break;
      default:
        throw std::runtime_error("Unknown action");
    }
  }
}

void add_submenu(vector<BookEntry>& book) {
  bool error = false;
  string name, phone, email;
  while (true) {
    cli::clear_terminal();
    std::cout << " --- " << modify_menu_title << " | Add" << " --- \n";
    std::cout << "Add a new entry to the book." << "\n\n";
    if (name.empty()) {
      if (error) {
        std::cout << "Input can't be empty, try again." << std::endl;
      }
      name = cli::read_line("Enter name");
      if (name.empty()) {
        error = true;
        continue;
      }
      error = false;
      continue;
    }
    std::cout << "Name: " << name << '\n';

    if (phone.empty()) {
      if (error) {
        std::cout << "Input can't be empty, try again." << std::endl;
      }
      phone = cli::read_line("Enter phone");
      if (phone.empty()) {
        error = true;
        continue;
      }
      error = false;
      continue;
    }
    std::cout << "Phone: " << phone << '\n';

    if (email.empty()) {
      if (error) {
        std::cout << "Input can't be empty, try again." << std::endl;
      }
      email = cli::read_line("Enter email");
      if (email.empty()) {
        error = true;
        continue;
      }
      error = false;
      continue;
    }
    std::cout << "Email: " << email << '\n';

    phone_book::add_entry(book, name, phone, email);
    std::cout << "\nEntry added.\n";
    cli::wait_for_input();
    break;
  }
}

void remove_submenu(vector<BookEntry>& book) {
  bool error = false, got_id = false;
  size_t id = 0;
  while (true) {
    cli::clear_terminal();
    std::cout << " --- " << modify_menu_title << " | Remove" << " --- \n";
    std::cout << "Remove an entry from the book." << "\n\n";
    if (!got_id) {
      if (error) std::cout << "This ID doesn't exist, try again.\n";
      if (auto i = cli::read_value<size_t>("Enter ID (0 to cancel)")) {
        if (*i == 0) {
          break;
        }
        if (*i - 1 < book.size()) {
          id = *i - 1;
          got_id = true;
          continue;
        }
      }
      error = true;
      continue;
    }
    std::cout << "ID: " << id + 1 << std::endl;

    vector<string> table = phone_book::to_table({1, book[id]});
    std::cout << "Removing the following entry:\n";
    for (const string& line : table) {
      std::cout << line << '\n';
    }
    std::cout << std::endl;
    string ans = cli::read_line("Are you sure? (y/N):");
    if (ans == "y" || ans == "Y") {
      phone_book::remove_entry(book, id);
      std::cout << "Entry with ID " << id + 1 << " removed.\n";
    } else {
      std::cout << "Aborting.\n";
    }
    cli::wait_for_input();
    break;
  }
}

void edit_submenu(vector<BookEntry>& book) {
  bool error = false, got_id = false;
  string name, phone, email;
  size_t id = 0;
  while (true) {
    cli::clear_terminal();
    std::cout << " --- " << modify_menu_title << " | Edit" << " --- \n";
    std::cout << "Edit an entry in the book." << "\n\n";
    if (!got_id) {
      if (error) std::cout << "This ID doesn't exist, try again.\n";
      if (auto i = cli::read_value<size_t>("Enter ID (0 to cancel)")) {
        if (*i == 0) {
          break;
        }
        if (*i - 1 < book.size()) {
          id = *i - 1;
          got_id = true;
          continue;
        }
      }
      error = true;
      continue;
    }
    std::cout << "ID: " << id + 1 << std::endl;

    vector<string> table = phone_book::to_table({1, book[id]});
    std::cout << "Editing the following entry:\n";
    for (const string& line : table) {
      std::cout << line << '\n';
    }
    std::cout << std::endl;
    if (name.empty()) {
      name = cli::read_line(string("Edit name (") + book[id].name + ")");
      if (name.empty()) {
        name = book[id].name;
      }
      continue;
    }
    std::cout << "Name: " << name << '\n';

    if (phone.empty()) {
      phone = cli::read_line(string("Edit phone (") + book[id].phone + ")");
      if (phone.empty()) {
        phone = book[id].phone;
      }
      continue;
    }
    std::cout << "Phone: " << phone << '\n';

    if (email.empty()) {
      email = cli::read_line(string("Edit email (") + book[id].email + ")");
      if (email.empty()) {
        email = book[id].email;
      }
      continue;
    }
    std::cout << "Email: " << email << '\n';

    phone_book::edit_entry(book, id, name, phone, email);
    std::cout << "\nEntry edited.\n";
    cli::wait_for_input();
    break;
  }
}