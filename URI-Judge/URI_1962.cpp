#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, x, aux;
  cin >> n;
  while(n){
    cin >> x;
    if (x < 2015) cout << 2015-x << " D.C." << endl;
    else cout << x-2014 << " A.C." << endl;
    n--;
  }
}
