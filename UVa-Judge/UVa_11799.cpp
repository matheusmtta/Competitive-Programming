/*
* Horror Dash
* UVa Online Judge 11799
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k = 1;
  while(n--){
    int x, ans=0, y;
    cin >> x;
    for (int i = 0; i < x; i++){
      cin >> y;
      ans = max(ans, y);
    }
    printf("Case %d: %d\n",k, ans);
    k++;
  }
  return 0;
}
