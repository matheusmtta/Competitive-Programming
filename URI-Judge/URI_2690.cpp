/*
* Nova Senha RA
* URI Online Judge 2690
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

char identify(char a){
  if (a == 'G' || a == 'Q' || a == 'a' || a == 'k' || a == 'u') return '0';
  else if (a == 'I' || a == 'S' || a == 'b' || a == 'l' || a == 'v') return '1';
  else if (a == 'E' || a == 'O' || a == 'Y' || a == 'c' || a == 'm' || a == 'w') return '2';
  else if (a == 'F' || a == 'P' || a == 'Z' || a == 'd' || a == 'n' || a == 'x') return '3';
  else if (a == 'J' || a == 'T' || a == 'e' || a == 'o' || a == 'y') return '4';
  else if (a == 'D' || a == 'N' || a == 'X' || a == 'f' || a == 'p' || a == 'z') return '5';
  else if (a == 'A' || a == 'K' || a == 'U' || a == 'g' || a == 'q') return '6';
  else if (a == 'C' || a == 'M' || a == 'W' || a == 'h' || a == 'r') return '7';
  else if (a == 'B' || a == 'L' || a == 'V' || a == 'i' || a == 's') return '8';
  else if (a == 'H' || a == 'R' || a == 'j' || a == 't') return '9';
}

int main(){
  char str[1000], use;
  int n, i=0, aux=0;
  scanf("%d", &n);
  while(n--){
    scanf(" %[^\n]", str);
    i = 0;
    aux = 0;
    while(str[i]){
      if (isalpha(str[i])){
        if (aux < 12){
          cout << identify(str[i]);
          aux++;
        }
      }
      i++;
    }
    cout << endl;
  }
}
