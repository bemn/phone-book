#include "phone_book.h"

#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

void add_entry(vector<BookEntry>& book, const string& name, const string& phone,
               const string& email) {
  book.push_back({name, phone, email});
}

void remove_entry(vector<BookEntry>& book, const size_t id) {
  if (id >= book.size()) {
    throw std::out_of_range("id is out of range");
  }
  for (size_t i = id; i < book.size() - 1; i++) {
    book[i] = book[i + 1];
  }
  book.pop_back();
}

void edit_entry(vector<BookEntry>& book, const size_t id, const BookField field,
                const string& value) {
  switch (field) {
    case NAME:
      book[id].name = value;
      break;
    case PHONE:
      book[id].phone = value;
      break;
    case EMAIL:
      book[id].email = value;
      break;
  }
}

vector<size_t> find_by(const vector<BookEntry>& book, const BookField field,
                       const string& query) {
  vector<size_t> entries;
  for (size_t i = 0; i < book.size(); i++) {
    string value;
    switch (field) {
      case NAME:
        value = book[i].name;
        break;
      case PHONE:
        value = book[i].phone;
        break;
      case EMAIL:
        value = book[i].email;
        break;
    }
    if (value == query) {
      entries.push_back(i);
    }
  }
  return entries;
}
