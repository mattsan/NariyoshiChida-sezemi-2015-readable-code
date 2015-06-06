#include<bits/stdc++.h>

using namespace std;

void Output(string filename){

  fstream read_file(filename.c_str());
  string text;

  while( !( read_file >> text ).fail() ) {
    cout << text << endl;
  }

  read_file.close();

}

int main(int argc,char* argv[]){

  for(int i=1;i<argc;i++){
    Output(string(argv[i]));
  }

  return 0;
}
