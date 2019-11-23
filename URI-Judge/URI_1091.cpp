/*
* Divisão da Nlogônia
* URI Online Judge 1091
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;



int main(){
  int n, m, k;
  while(1){
    int x, y;
    cin >> k;
    if (k==0) break;
    cin >> n >> m;
    while(k--){
      cin >> x >> y;
      if (x==n || m==y) {cout << "divisa" << endl;}
      else if (x > n && y > m) {cout << "NE" << endl;}
      else if (x > n && y < m) {cout << "SE" << endl;}
      else if (x < n && y < m) {cout << "SO" << endl;}
      else if (x < n && y > m) {cout << "NO" << endl;}
    }
  }
}
