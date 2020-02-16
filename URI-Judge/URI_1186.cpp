#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n=0;
    float sum;
    float memo[12][12];
    char type;
    int k=0;
    cin >> type;
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
        cin >> memo[i][j];

    for (int i = 11; i > 0; i--){
      for (int j = 11; j > 0+k; j--){
        sum+=memo[i][j];
      }
      k++;
    }

    if (type =='S')
      printf("%.1f\n", sum);
    else
      printf("%.1f\n", sum/66);
}
