#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int n, m, f, aux;
  cin >> n >> m >> f;
  aux = (24+(n+(m+f)))%24;
  cout << aux << endl;
  return 0;
}
