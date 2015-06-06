$ はプロンプトを表す
$ の後に続くコマンドをターミナル上で入力することで実行できる

仕様1 :

実行方法
$ g++ recipe.cc
$ ./a.out
> オムライス

仕様3 :
recipe-data.txt にレシピ情報のデータが書き込まれている

実行方法
$ g++ recipe.cc
$ ./a.out recipe-data.txt

仕様4 :
recipe-data_spec4.txt にレシピ情報のデータが書き込まれている

データは１行に１つのレシピ情報をテキストで記述し、複数のデータを記述することができる

実行方法
$ g++ recipe.cc
$ ./a.out recipe-data_spec4.txt

仕様5 :
recipe-data_spec5.txt にレシピ情報のデータが書き込まれている

実行方法
$ g++ recipe.cc
$ ./a.out recipe-data_spec5.txt

仕様6 :
recipe-data_spec6.txt にレシピ情報のデータが書き込まれている

コンパイル
$ g++ recipe.cc

実行方法 1 : 全レシピを出力
$ ./a.out recipe-data_spec6.txt

実行方法 2 : 指定した ID のレシピのみを出力。ID はコマンドのパラメータとして指定する
$ ./a.out recipe-data_spec6.txt 1

仕様7 :
recipe-data_spec7.txt にレシピ情報のデータが書き込まれている

データは１行に１つのレシピ情報をテキストで記述し、複数のデータを記述することができる

レシピ情報は、料理名とクックパッドのURLを空白で区切り１行に記述する

コンパイル
$ g++ recipe.cc

実行方法 1 : 全レシピを出力
$ ./a.out recipe-data_spec7.txt

実行方法 2 : 指定した ID のレシピのみを出力。ID はコマンドのパラメータとして指定する
$ ./a.out recipe-data_spec7.txt 1
