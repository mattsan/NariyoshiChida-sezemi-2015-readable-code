#include <algorithm>
#include <iostream>

#include "Recipe.h"

std::istream& Recipe::readFrom(std::istream& in) {
  std::string data;
  if(getline(in, data).good()) {
    std::size_t end_of_name = data.find_first_of(' ');
    std::size_t begin_of_url = data.find_first_not_of(' ', end_of_name);
    name_ = data.substr(0, end_of_name);
    url_  = data.substr(begin_of_url);
  }
  return in;
}

std::ostream& Recipe::writeTo(std::ostream& out) const {
  return out << id_ << ": " << name_ << ' ' << url_;
}

std::istream& operator >> (std::istream& in, Recipe& recipe) {
  return recipe.readFrom(in);
}

std::ostream& operator << (std::ostream& out, const Recipe& recipe) {
  return recipe.writeTo(out);
}

struct FindById {
  FindById(int id) : id(id) {}
  bool operator () (const Recipe& recipe) const {
    return recipe.id() == id;
  };

  const int id;
};

const Recipe& RecipeBook::findById(int id) const {
  std::vector<Recipe>::const_iterator i = std::find_if(recipeBook_.begin(), recipeBook_.end(), FindById(id));
  return *i;
}

bool RecipeBook::hasId(int id) const {
  std::vector<Recipe>::const_iterator i = std::find_if(recipeBook_.begin(), recipeBook_.end(), FindById(id));
  return i != recipeBook_.end();
}

std::istream& operator >> (std::istream& in, RecipeBook& recipeBook) {
  Recipe recipe;

  while(recipe.readFrom(in).good()) {
    recipeBook.append(recipe);
  }

  return in;
}

std::ostream& operator << (std::ostream& out, const RecipeBook& recipeBook) {
  for(int i = 0; i < recipeBook.size(); ++i) {
    out << recipeBook[i] << "\n";
  }
  return out;
}
