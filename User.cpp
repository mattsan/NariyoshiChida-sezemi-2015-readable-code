#include <iostream>

#include "User.h"

std::ostream& operator << (std::ostream& out, const User& user) {
  return out << user.name << "\n" << user.recipeBook;
}
