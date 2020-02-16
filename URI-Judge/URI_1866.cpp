#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    if (x%2 == 0) cout << "0" << endl;
    else cout << "1" << endl;
  }
}
