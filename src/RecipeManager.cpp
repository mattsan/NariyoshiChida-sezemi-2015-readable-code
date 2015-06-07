#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include "Recipe.h"
#include "User.h"

using namespace std;

int StrToInt(const string s) {
  stringstream ss;
  ss << s;
  int result;
  ss >> result;
  return result;
}

void LoadRecipe(const string& filename, RecipeBook& recipeBook) {
  ifstream file(filename.c_str());
  file >> recipeBook;
}

void PrintUsers(const Users& users, const string& id_str) {
  for(Users::const_iterator i = users.begin(); i != users.end(); ++i) {
    cout << "ユーザー名: " << i->name << "\n";
    if(id_str.empty()) {
      cout << i->recipeBook;
    } else if(i->recipeBook.hasId(StrToInt(id_str))) {
      cout << i->recipeBook.findById(StrToInt(id_str)) << endl;
    }
    cout << endl;
  }
}

int main(int argc,char* argv[]){
  std::string id_str = "";
  int initial_id = 1;
  Users users;

  int i = 1;
  while(i < argc) {
    string name = argv[i++];
    if(i >= argc) {
      id_str = name;
      break;
    }
    User user(name, initial_id);

    const std::string filename = argv[i++];

    LoadRecipe(filename, user.recipeBook);

    initial_id = user.recipeBook.current_id();

    users.push_back(user);
  }

  PrintUsers(users, id_str);

  return 0;
}
