/*
* Desvendando Monty Hall
* URI Online Judge 2879
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int x, y, n, ans=0;
  cin >> n;
  while(n--){
    cin >> x;
    if (x != 1) ans++;
  }
  cout << ans << endl;
}
