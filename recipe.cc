#include<bits/stdc++.h>

using namespace std;

void LoadRecipe(string filename){

  fstream file(filename.c_str());
  string text;

  // ファイルの中身を1行ずつ読み込み出力する
  while( !( file >> text ).fail() ) {
    cout << text << endl;
  }

  read_file.close();

}

int main(int argc,char* argv[]){


  // ./a.out の後に続くデータファイルの中身を順にロードする
  for(int i=1;i<argc;i++){
    LoadRecipe(string(argv[i]));
  }

  return 0;
}
