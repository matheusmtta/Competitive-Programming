/*
* Luzes de Natal
* URI Online Judge 2718
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  unsigned long long n, x, ones=0, ans=0, aux=0, i=0, j=0;
  cin >> n;
  while(n--){
    string str;
    cin >> x;
    while (x>=1){
      if (x%2==0) str+='0';
      else str+='1';
      x/=2;
    }
    for (unsigned long long int i = 0; i < str.length(); i++){
      if (str[i] == '1') ones++;
      else ones=0;
      ans = max(ans, ones);
    }
    ones=0;
    cout << ans << endl;
    ans=0;
  }
  return 0;
}
