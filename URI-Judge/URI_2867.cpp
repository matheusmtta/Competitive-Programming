/*
* Digitos
* URI Online Judge 2867
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, aux, q;
  cin >> n;
  while(n--){
    double x, y, ans;
    q=0;
    cin >> x >> y;
    ans = y*log10(x);
    printf("%d\n", (int)floor(ans)+1);
  }
}
