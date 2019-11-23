/*
* Summing Digits
* Uva Online Judge 11332
* 11/07/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

unsigned long long int sumdigits(unsigned long long int x){
  unsigned long long ans=0;
  while (x >= 1){
    ans+=(x%10);
    x/=10;
  }
  return ans;
}

int main(){
  while(1){
    unsigned long long n, ans;
    cin >> n;
    if (n==0) return 0;
    ans = sumdigits(sumdigits(sumdigits(n)));
    cout << ans << endl;
  }
  return 0;
}
