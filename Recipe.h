#ifndef RECIPE_H
#define RECIPE_H

#include <iosfwd>
#include <string>

class Recipe {
public:
  std::istream& readFrom(std::istream& in);
  std::ostream& writeTo(std::ostream& out) const;

private:
  std::string name_;
  std::string url_;
};

std::istream& operator >> (std::istream& in, Recipe& recipe);
std::ostream& operator << (std::ostream& out, const Recipe& recipe);

#endif//RECIPE_H
