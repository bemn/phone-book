#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace phone_book {

struct BookEntry {
  string name;
  string phone;
  string email;
};

enum BookField { NAME, PHONE, EMAIL };

void add_entry(vector<BookEntry> &book, const string &name, const string &phone,
               const string &email);

void remove_entry(vector<BookEntry> &book, size_t id);

void edit_entry(vector<BookEntry> &book, size_t id, const string &name,
                const string &phone, const string &email);

vector<size_t> find_by(const vector<BookEntry> &book, BookField field,
                       const string &query);

vector<string> to_table(const vector<BookEntry> &book);

}  // namespace phone_book