/*
* Código Secreto
* URI Online Judge 2727
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

char letters[27] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                               'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                                'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main(){
  int n, count=0, i=0, aux=0, points=0;
  string str;
  while(cin >> n){
    getchar();
    while(n--){
      getline(cin, str);
      //out << str << endl;
      if (str.length() <= 3){
        if (str.length() == 1) cout << 'a' << endl;
        else if (str.length() == 2) cout << 'b' << endl;
        else if (str.length() == 3 && str[1] == ' ') cout << 'd' << endl;
        else cout << 'c' << endl;
      }
      else{
        if (str[0] == '.' && str[1] == ' ') aux=1;
        else if (str[0] == '.' && str[1] == '.' && str[2] == ' ') aux=2;
        else if (str[0] == '.' && str[1] == '.' && str[2] == '.') aux=3;
        for (int i = 0; i < str.length(); i++)
          if (str[i] == ' ') count++;
        //cout << count << endl;
        if (aux == 1) cout << letters[1+3*(count)] << endl;
        else if (aux == 2) cout << letters[2+3*(count)] << endl;
        else cout << letters[3+3*(count)] << endl;
      }
      aux=0;
      count=0;
    }
  }
  return 0;
}
