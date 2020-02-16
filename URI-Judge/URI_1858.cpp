#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, m, b, c, a;
  cin >> n;
  b = INF;
  for (int i = 0; i < n; i++){
    cin >> a;
    if (b > a){
      m = i;
      b = a;
    }
  }
  cout << m+1 << endl;
  return 0;
}
