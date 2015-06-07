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
  const std::string url() const  { return url_;  }
  int               id() const   { return id_;   }

private:
  std::string name_;
  std::string url_;
  int         id_;
};

std::istream& operator >> (std::istream& in, Recipe& recipe);
std::ostream& operator << (std::ostream& out, const Recipe& recipe);

class RecipeBook {
public:
  RecipeBook() : recipeBook_(), current_id_(1) {}
  RecipeBook(int initial_id) : recipeBook_(), current_id_(initial_id) {}

  std::size_t   size() const              { return recipeBook_.size(); }
  const Recipe& operator [] (int i) const { return recipeBook_[i];     }
  int           current_id() const        { return current_id_;        }

  void append(const Recipe& recipe);
  const Recipe& findById(int id) const;
  bool hasId(int id) const;

private:
  std::vector<Recipe> recipeBook_;
  int                 current_id_;
};

std::istream& operator >> (std::istream& in, RecipeBook& recipeBook);
std::ostream& operator << (std::ostream& out, const RecipeBook& recipeBook);

#endif//RECIPE_H
