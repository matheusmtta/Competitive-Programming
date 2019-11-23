/*
* Automatic Answer
* Uva Online Judge 11547
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    int ans = (x*63+7492)*5-498;
    ans/=10;
    cout << abs(ans%10) << endl;
  }
}
