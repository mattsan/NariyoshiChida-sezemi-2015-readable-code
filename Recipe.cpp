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

const Recipe& Recipes::findById(int id) const {
  return recipes_[id - 1];
}

std::istream& operator >> (std::istream& in, Recipes& recipes) {
  Recipe recipe;

  int id = 1;
  while(recipe.readFrom(in).good()) {
    recipe.setId(id);
    recipes.push_back(recipe);
    ++id;
  }

  return in;
}

std::ostream& operator << (std::ostream& out, const Recipes& recipes) {
  for(int i = 0; i < recipes.size(); ++i) {
    out << recipes[i] << "\n";
  }
  return out;
}
