/*
* TEX Quotes
* UVa Online Judge 272
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  string str;
  int aux=0;
  while(getline(cin, str)){
    for (int i = 0; i < str.length(); i++){
      if (str[i]==34 && aux==0) {cout << "``"; aux=1;}
      else if (str[i]==34 && aux==1) {cout << "''"; aux=0;}
      else cout << str[i];
    }
    cout << endl;
  }
}
