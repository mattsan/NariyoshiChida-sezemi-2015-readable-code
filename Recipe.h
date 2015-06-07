#ifndef RECIPE_H
#define RECIPE_H

#include <iosfwd>
#include <string>
#include <vector>

class Recipe {
public:
  Recipe() : name_(), url_(), id_(0) {}
  std::istream& readFrom(std::istream& in);
  std::ostream& writeTo(std::ostream& out) const;

  void setName(const std::string& name) { name_ = name; }
  void setUrl(const std::string& url)   { url_  = url;  }
  void setId(int id)                    { id_   = id;   }

  const std::string name() const { return name_; }
  const std::string url() const  { return url_; }
  int               id() const   { return id_; }

private:
  std::string name_;
  std::string url_;
  int         id_;
};

std::istream& operator >> (std::istream& in, Recipe& recipe);
std::ostream& operator << (std::ostream& out, const Recipe& recipe);

class Recipes {
public:
  Recipes() : recipes_(), current_id_(1) {}
  Recipes(int initial_id) : recipes_(), current_id_(initial_id) {}

  void append(const Recipe& recipe) {
    recipes_.push_back(recipe);
    recipes_.back().setId(current_id_++);
  }

  std::size_t   size() const                    { return recipes_.size();     }
  const Recipe& operator [] (int i) const       { return recipes_[i];         }
  int current_id() const { return current_id_; }

  const Recipe& findById(int id) const;
  bool hasId(int id) const;

private:
  std::vector<Recipe> recipes_;
  int                 current_id_;
};

std::istream& operator >> (std::istream& in, Recipes& recipes);
std::ostream& operator << (std::ostream& out, const Recipes& recipes);

#endif//RECIPE_H
