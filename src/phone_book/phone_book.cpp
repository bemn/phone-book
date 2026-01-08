#include "phone_book/phone_book.h"

#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace phone_book {

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

void edit_entry(vector<BookEntry>& book, const size_t id, const string& name,
                const string& phone, const string& email) {
  if (!name.empty()) {
    book[id].name = name;
  }
  if (!phone.empty()) {
    book[id].phone = phone;
  }
  if (!email.empty()) {
    book[id].email = email;
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
    if (value.find(query) != string::npos) {
      entries.push_back(i);
    }
  }
  return entries;
}

vector<string> to_table(const vector<BookEntry>& book) {
  int max_name = -1, max_phone = -1, max_email = -1;
  for (const auto& entry : book) {
    max_name = std::max(static_cast<int>(entry.name.length()), max_name);
    max_phone = std::max(static_cast<int>(entry.phone.length()), max_phone);
    max_email = std::max(static_cast<int>(entry.email.length()), max_email);
  }
  int max_id = static_cast<int>(std::to_string(book.size()).length());

  // Lengths of corresponding headers
  max_id = std::max(2, max_id);
  max_name = std::max(4, max_name);
  max_phone = std::max(5, max_phone);
  max_email = std::max(5, max_email);

  auto table = vector<string>(book.size() + 1);
  std::stringstream stream;
  stream << " | " << std::right << std::setw(max_id) << "ID"
         << " | " << std::right << std::setw(max_name) << "NAME"
         << " | " << std::right << std::setw(max_phone) << "PHONE"
         << " | " << std::right << std::setw(max_email) << "EMAIL"
         << " | ";
  table[0] = stream.str();
  for (int i = 0; i < book.size(); i++) {
    stream.str("");
    stream.clear();
    stream << " | " << std::left << std::setw(max_id) << i + 1 << " | "
           << std::left << std::setw(max_name) << book[i].name << " | "
           << std::left << std::setw(max_phone) << book[i].phone << " | "
           << std::left << std::setw(max_email) << book[i].email << " | ";
    table[i + 1] = stream.str();
  }
  return table;
}

}  // namespace phone_book
