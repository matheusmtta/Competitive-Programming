/*
* Umil Bolt
* URI Online Judge 2863
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    float x, ans=10000;
    for (int i = 0; i < n; i++){
      cin >> x;
      ans = min(ans, x);
    }
    printf("%.2f\n", ans);
  }
}
