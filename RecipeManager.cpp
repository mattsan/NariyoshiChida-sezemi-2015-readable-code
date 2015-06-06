#include <fstream>
#include <iostream>
#include <sstream>

#include "Recipe.h"

using namespace std;

int StrToInt(const string s) {
  stringstream ss;
  ss << s;
  int result;
  ss >> result;
  return result;
}

void LoadRecipe(const string& filename, Recipes& recipes) {
  ifstream file(filename.c_str());
  file >> recipes;
}

void PrintRecipe(const Recipes& recipes, const string& id_str) {
  if(id_str.empty()) {
    cout << recipes;
  } else {
    cout << recipes.findById(StrToInt(id_str)) << endl;
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
