#pragma once

#include <array>
#include <string>

using std::array;
using std::string;

// Main menu
inline const string main_menu_title = "Phone Book";
inline const string main_menu_desc =
    "You can search for entries with 'query',\n"
    "add, remove or edit them with 'modify,\n"
    "and export to or import the book from the file.";
inline const array<string, 3> main_menu_items{"Query", "Modify", "Export/Import"};

// Query menu
inline const string query_menu_title = "Phone Book | Query";
inline const string query_menu_desc =
    "Find entries by (partial) name, phone or email.\n"
    "Retrieved data will be sorted alphabetically by name.\n"
    "You can also use 'show all' to display every entry\n"
    "in the book at once.";
inline const array<string, 4> query_menu_items{"Find by name", "Find by phone",
                                               "Find by email", "Show all"};

// Modify menu
inline const string modify_menu_title = "Phone Book | Modify";
inline const string modify_menu_desc =
    "Add new entries with 'add', remove with 'remove',\n"
    "edit them with 'edit'.";
inline const array<string, 3> modify_menu_items{"Add new", "Remove by ID",
                                                "Edit by ID"};

// Save/Load menu
inline const string saveload_menu_title = "Phone Book | Export/Import";
inline const string saveload_menu_desc =
    "Export current book to a specified file with 'export'\n"
    "or load from a file using 'import'.";
inline const array<string, 2> saveload_menu_items{"Export to", "Import from"};
