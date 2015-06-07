#ifndef USER_H
#define USER_H

#include <iosfwd>
#include <string>

#include "Recipe.h"

struct User {
  User(const std::string& name, int initial_id) : name(name), recipeBook(initial_id) {}

  std::string name;
  RecipeBook  recipeBook;
};

std::ostream& operator << (std::ostream& out, const User& user);

typedef std::vector<User> Users;

#endif//USER_H
