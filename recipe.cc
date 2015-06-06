#include<bits/stdc++.h>

using namespace std;

void LoadRecipe(string filename){

  fstream file(filename.c_str());
  string text;

  // ファイルの中身を1行ずつ読み込み出力する
  int identifier_of_recipe = 1;
  while( !( file >> text ).fail() ) { 
    cout << identifier_of_recipe << ": " << text << endl;
    ++identifier_of_recipe;
  }

  file.close();

}

int main(int argc,char* argv[]){


  // ./a.out の後に続くデータファイルの中身を順にロードする
  for(int i=1;i<argc;i++){
    LoadRecipe(string(argv[i]));
  }

  return 0;
}
