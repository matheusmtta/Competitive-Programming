/*
* Laser Sculpture
* UVa Online Judge 11683 
* 21/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, k, x, y, ans;
  while(true){
    cin >> n;
    if (n==0) return 0;
    cin >> k;
    x = n;
    ans = 0;
    for (int i = 0; i < k; i++){
      cin >> y;
      if (x > y) ans+=(x-y);
      x = y;
    }
    cout << ans << endl;
  }
  return 0;
}