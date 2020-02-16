#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int x, y=0, z, w;
  for (int i = 0; i < 4; i++){
    cin >> x;
    y+=x;
  }
  cout << y-3 << endl;
  return 0;
}
