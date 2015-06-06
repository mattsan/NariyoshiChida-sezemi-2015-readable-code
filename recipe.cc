#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<string> recipe_data_t;

int StrToInt(const string s) {
  stringstream ss;
  ss << s;
  int result;
  ss >> result;
  return result;
}

void LoadRecipe(const string filename, recipe_data_t& recipeData) {
  fstream file(filename.c_str());
  string  text;

  while( !( file >> text ).fail() ) {
    ostringstream oss;
    oss << text;
    recipeData.push_back(oss.str());
  }
}

void PrintRecipe(const recipe_data_t& recipeData, const string& id_str) {
  if(id_str.empty()) {
    for(int i = 0; i < recipeData.size(); ++i) {
      cout << (i + 1) << ": " << recipeData[i] << endl;
    }
  } else {
    int id_number = StrToInt(id_str);
    cout << id_number << ": " << recipeData[id_number - 1] << endl;
  }
}

int main(int argc,char* argv[]){
  const std::string filename = argv[1];
  const std::string id_str   = (argc > 2) ? argv[2] : "";

  recipe_data_t recipeData;

  LoadRecipe(filename, recipeData);
  PrintRecipe(recipeData, id_str);

  return 0;
}
