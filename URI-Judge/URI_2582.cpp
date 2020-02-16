#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  string str, base = "Pizza antes de FdI";
  int x, aux = 0, aux2 = 0, aux3 = 0;
  while (cin >> m >> n){
    for (int i = 0; i < n; i++){
      cin >> str;
      cin.ignore();
      for (int j = 0; j < m; j++){
        cin >> x;
        if (x == 0) aux = 1;
      }
      if (aux == 0 && aux2 == 0) {cout << str << endl; aux2 = 1; aux3 =1;}
      aux = 0;
    }
    if (!aux3) cout << base << endl;
    aux3 = aux2 = aux = 0;
  }
  return 0;
}
