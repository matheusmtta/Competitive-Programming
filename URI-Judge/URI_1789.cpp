#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int x, y, z;
  while (scanf("%d", &x) != EOF){
    int maxi = 0;
    for (int i = 0; i < x; i++){
      cin >> y;
      maxi = max(y, maxi);
    }
    if (maxi < 10) cout << "1" << endl;
    else if (maxi >= 10 && maxi < 20) cout << "2" << endl;
    else if (maxi >= 20) cout << "3" << endl;
  }
}
