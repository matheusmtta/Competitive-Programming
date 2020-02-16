#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n=0;
    float sum;
    float memo[12][12];
    cin >> n;
    char type;
    cin >> type;
    for (int i = 0; i < 12; i++){
      for (int j = 0; j < 12; j++){
        cin >> memo[i][j];
      }
    }
    for (int i = 0; i <12; i++)
      sum+=memo[i][n];
    if (type =='S')
      printf("%.1f\n", sum);
    else
      printf("%.1f\n", sum/12);
}
