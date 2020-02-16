#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, a, b, c;
  int x, aux = 0, aux2 = 0, aux3 = 0;
  while (cin >> n >> a){
    for (int i = 0; i < n; i++){
      cin >> b >> m;
      if (a == b && m == 0) aux++;
    }
    cout << aux << endl;
    aux = 0;
  }
  return 0;
}
