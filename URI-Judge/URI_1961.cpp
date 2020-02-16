#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, m, imp=0;
  cin >> n >> m;
  int canos[m];
  cin >> canos[0];
  for (int i = 1; i < m; i++){
      cin >> canos[i];
      if(n >= abs(canos[i]-canos[i-1])) imp++;
  }
  if (imp == m-1) cout << "YOU WIN" << endl;
  else cout << "GAME OVER" << endl;
}
