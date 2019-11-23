/*
* Zapping
* UVa Online Judge 12468
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int ans1, ans2;
  int x, y;
  while(1){
    cin >> x >> y;
    if (x==-1 || y==-1) return 0;
    if (x > y){
      ans1=x-y;
      ans2=y+100-x;
    }
    else {
      ans1=y-x;
      ans2=x+100-y;
    }
    cout << min(ans1, ans2) << endl;
  }
  return 0;
}
