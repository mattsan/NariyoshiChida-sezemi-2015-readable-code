#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int StrToInt(const string s) {
  stringstream ss;
  ss << s;
  int result;
  ss >> result;
  return result;
}

class Recipe {
public:
  istream& readFrom(istream& in) {
    string data;
    if(getline(in, data).good()) {
      size_t end_of_name = data.find_first_of(' ');
      size_t begin_of_url = data.find_first_not_of(' ', end_of_name);
      name_ = data.substr(0, end_of_name);
      url_  = data.substr(begin_of_url);
    }
    return in;
  }

  ostream& writeTo(ostream& out) const {
    return out << name_ << ' ' << url_;
  }

private:
  string name_;
  string url_;
};

istream& operator >> (istream& in, Recipe& recipe) {
  return recipe.readFrom(in);
}

ostream& operator << (ostream& out, const Recipe& recipe) {
  return recipe.writeTo(out);
}

typedef vector<Recipe> Recipes;

void LoadRecipe(const string filename, Recipes& recipes) {
  ifstream file(filename.c_str());
  Recipe   recipe;

  while(recipe.readFrom(file).good()) {
    recipes.push_back(recipe);
  }
}

void PrintRecipe(const Recipes& recipes, const string& id_str) {
  if(id_str.empty()) {
    for(int i = 0; i < recipes.size(); ++i) {
      cout << (i + 1) << ": " << recipes[i] << endl;
    }
  } else {
    int id_number = StrToInt(id_str);
    cout << id_number << ": " << recipes[id_number - 1] << endl;
  }
}

int main(int argc,char* argv[]){
  const std::string filename = argv[1];
  const std::string id_str   = (argc > 2) ? argv[2] : "";

  Recipes recipes;

  LoadRecipe(filename, recipes);
  PrintRecipe(recipes, id_str);

  return 0;
}
