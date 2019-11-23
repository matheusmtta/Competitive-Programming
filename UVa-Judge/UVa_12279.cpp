/*
* Emoogle Balance
* Uva Online Judge 12279
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = 0, k=1;
  while(1){
    cin >> n;
    int count=0;
    if (n==0) return 0;
    int numbers=0;
    for (int i = 0; i < n; i++){
      int x;
      cin >> x;
      if (x==0) count++;
      else numbers++;
    }
    int ans = numbers-count;
    printf("Case %d: %d\n",k, ans);
    k++;
  }
}
