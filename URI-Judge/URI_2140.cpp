#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    int sums[] = {7, 12, 22, 52, 102, 15, 25, 55, 105, 30, 60, 110, 70, 120, 150};
    while(1){
      cin >> n >> m;
      int ans=1;
      if (n == 0 && m == 0) return 0;
      for (int i = 0; i < 15; i++){
        if ((m-n)-sums[i] == 0) {cout << "possible" << endl; ans=0; break;}
      }
      if (ans) cout << "impossible" << endl;
    }
    return 0;
}
