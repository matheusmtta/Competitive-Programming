/*
* Zeros and Ones
* UVa Online Judge 10324
* 18/10/2019
* matheusmtta (Matheus Motta)
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k=1, aux=0;
  int x, y, i, j;
  int m;
  string zo;
  int zeros=0, ones=0;
  while(true){
    cin >> zo;
    cin >> m;
    for (int s = 0; s < m; s++){
      if (s==0) cout << "Case " << k << ":" << endl;
      if (1==zo.length()) {cout << "Yes" << endl;}
      cin >> x >> y;
      if (x==0 && y==0) return 0;
      i = min(x, y);
      j = max(x, y);
      ones=zeros=0;
      for (int l = i; l <= j; l++){
        //cout << zo[l];
        if (zo[l]=='1') ones++;
        else if (zo[l]=='0') zeros++;
      }
      //cout << endl;
      if (zeros == 0 || ones==0) cout << "Yes" << endl;
      else cout << "No" << endl;
      aux=0;
    }
    k++;
  }
  return 0;
}
