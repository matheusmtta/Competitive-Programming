/*
* O jogo Matemático de Paula
* URI Online Judge 1192
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y;
  string str;
  int n;
  cin >> n;
  while (n--){
    cin >> str;
    if (str[0] == str[2]){
      cout << (str[0]-'0')*(str[2]-'0') << endl;
    }
    else{
      if (str[1] >= 65 && str[1] <= 90)
        cout << -(str[0]-'0')+(str[2]-'0') << endl;
      else
        cout << (str[0]-'0')+(str[2]-'0') << endl;
    }
  }
}
