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

  // ファイルの中身を1行ずつ読み込み出力する
  while( !( file >> text ).fail() ) {
    ostringstream oss;
    oss << text;
    recipeData.push_back(oss.str());
  }
}

void PrintRecipe(const recipe_data_t& recipeData, const string& id) {
  if(id.empty()) {
    for(int i = 0; i < recipeData.size(); ++i) {
      cout << (i + 1) << ": " << recipeData[i] << endl;
    }
  } else {
    int id_number = StrToInt(id);
    cout << id_number << ": " << recipeData[id_number - 1] << endl;
  }
}

int main(int argc,char* argv[]){
  std::string filename = argv[1];
  std::string id       = (argc > 2) ? argv[2] : "";
  recipe_data_t recipeData;

  LoadRecipe(filename, recipeData);
  PrintRecipe(recipeData, id);

  return 0;
}
