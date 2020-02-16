#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, b, c, r;
  cin >> a >> b;
  int q=0; r=0;
  int aux = a;
  if (a < 0){
    if (b>0){
      while(aux < 0){
        aux+=b;
        q--;
      }
      r  = aux;
      cout << q << " " << r << endl;
    }
    else if (b < 0){
      b = abs(b);
      aux = a;
      while(aux < 0){
        aux+=b;
        q++;
      }
      r  = aux;
      cout << q << " " << r << endl;
    }
  }
  else cout << a/b << " " << a%b << endl;
  return 0;
}
