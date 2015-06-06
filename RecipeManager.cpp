#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Recipe.h"

using namespace std;

int StrToInt(const string s) {
  stringstream ss;
  ss << s;
  int result;
  ss >> result;
  return result;
}

typedef vector<Recipe> Recipes;

istream& operator >> (istream& in, Recipes& recipes) {
  Recipe recipe;

  while(recipe.readFrom(in).good()) {
    recipes.push_back(recipe);
  }

  return in;
}

ostream& operator << (ostream& out, const Recipes& recipes) {
  for(int i = 0; i < recipes.size(); ++i) {
    out << (i + 1) << ": " << recipes[i] << "\n";
  }
  return out;
}

void LoadRecipe(const string& filename, Recipes& recipes) {
  ifstream file(filename.c_str());
  file >> recipes;
}

void PrintRecipe(const Recipes& recipes, const string& id_str) {
  if(id_str.empty()) {
    cout << recipes;
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
