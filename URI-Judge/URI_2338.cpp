#include <bits/stdc++.h>

using namespace std;

void morse(string sub){
  if(sub == "=.===") cout << "a";
  else if(sub == "===.=.=.=") cout << "b";
  else if(sub == "===.=.===.=") cout << "c";
  else if(sub == "===.=.=") cout << "d";
  else if(sub == "=") cout << "e";
  else if(sub == "=.=.===.=") cout << "f";
  else if(sub == "===.===.=") cout << "g";
  else if(sub == "=.=.=.=") cout << "h";
  else if(sub == "=.=") cout << "i";
  else if(sub == "=.===.===.===") cout << "j";
  else if(sub == "===.=.===") cout << "k";
  else if(sub == "=.===.=.=") cout << "l";
  else if(sub == "===.===") cout << "m";
  else if(sub == "===.=") cout << "n";
  else if(sub == "===.===.===") cout << "o";
  else if(sub == "=.===.===.=") cout << "p";
  else if(sub == "===.===.=.===") cout << "q";
  else if(sub == "=.===.=") cout << "r";
  else if(sub == "=.=.=") cout << "s";
  else if(sub == "===") cout << "t";
  else if(sub == "=.=.===") cout << "u";
  else if(sub == "=.=.=.===") cout << "v";
  else if(sub == "=.===.===") cout << "w";
  else if(sub == "===.=.=.===") cout << "x";
  else if(sub == "===.=.===.===") cout << "y";
  else if(sub == "===.===.=.=") cout << "z";
}

int main(){
  int n = 0, inicio=0, u=0, k=0, j=0, aux=0;
  string str, sub;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> str;
    j = 0;
    while(j < str.length()){
      if (str[j+1] == '.' && str[j+2] == '.' && str[j+3] == '.'){
        aux = 1;
        if (str[j+4] == '.' && str[j+5] == '.' && str[j+6] == '.')
          aux = 2;
      }
      sub += str[j];
      if (j == str.length()-1) {morse(sub); cout << endl; sub.erase(); break;}
      if (aux == 1) {morse(sub); aux = 0; j+=4; sub.erase(); continue;}
      else if (aux == 2) {morse(sub); cout << " "; j+=8; aux = 0; sub.erase(); continue;}
      j++;
    }
  }
  return 0;
}
