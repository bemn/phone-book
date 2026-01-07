#pragma once

#include <vector>

#include "phone_book/phone_book.h"

void query_menu(const std::vector<phone_book::BookEntry>& book);
void modify_menu(std::vector<phone_book::BookEntry>& book);
void saveload_menu(std::vector<phone_book::BookEntry>& book);
