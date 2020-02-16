#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n=0;
    float sum;
    float memo[12][12];
    char type;
    cin >> type;
    for (int i = 0; i < 12; i++){
      for (int j = 0; j < 12; j++){
        cin >> memo[i][j];
        if (j < i) sum+=memo[i][j];
      }
    }
    if (type =='S')
      printf("%.1f\n", sum);
    else
      printf("%.1f\n", sum/66);
}
