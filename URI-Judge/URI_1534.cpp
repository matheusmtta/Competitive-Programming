#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n;
    while(scanf("%d", &n) != EOF){
      int memo[n][n];
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          if (i == j) memo[i][j] = 1;
          else memo[i][j] = 3;
        }
      }
      int k = n-1;
      for (int i = 0; i < n; i++){
        memo[i][k] = 2;
        k--;
      }
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          cout << memo[i][j];
        }
        cout << endl;
      }
    }

}
