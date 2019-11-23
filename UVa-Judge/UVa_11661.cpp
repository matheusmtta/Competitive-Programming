/*
* Burger Time?
* UVa Online Judge 11661 
* 21/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, ans;
  string str;
  while(true){
    cin >> n;
    if (n==0) return 0;
    cin >> str;
    int dist=n, ld=-n, lr=-n;
    for (int i = 0; i < n; i++){
      if (str[i]=='Z') {dist = 0; break;}
      else if (str[i]=='R'){
        dist = min(dist, i-ld);
        lr = i;
      }
      else if (str[i]=='D'){
        dist = min(dist, i-lr);
        ld = i;
      }
    }
    cout << dist << endl;
  } 
  return 0;
}