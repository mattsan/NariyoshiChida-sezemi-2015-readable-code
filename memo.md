仕様3:

### 実際のコード
void LoadRecipe(string filename)

### どうしてリーダブルだと思っているかの説明
この関数を呼び出すことで filename で指定したファイルの中身がロードされるということが関数名から理解できる

### この書き方の一言説明

仕様5:

### 実際のコード
int identifier_of_recipe = 1;
while( !( file >> text ).fail() ) { 
  cout << identifier_of_recipe << ": " << text << endl;
  ++identifier_of_recipe;
}

### どうしてリーダブルだと思っているかの説明
レシピを一意に識別できる識別子の名前を変数名にすることで読んだ人はすぐに理解できる

### この書き方の一言説明
