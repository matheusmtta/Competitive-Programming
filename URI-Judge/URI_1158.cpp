#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, sum=0, cases;
    cin >> cases;
    while (cases--){
      cin >> n >> m;
      while (m){
        if (n%2 == 1 || n%2 == -1){
          m--;
          sum+=n;
        }
        n++;
      }
      cout << sum << endl;
      sum = 0;
    }
    return 0;
}
