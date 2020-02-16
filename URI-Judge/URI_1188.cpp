#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n=0;
    double sum;
    double memo[12][12];
    char type;
    int q = 1;
    int p = 10;
    cin >> type;
    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++)
        cin >> memo[i][j];

    for (int i = 11; i >= 7; i--){
      for (int j = q; j <= p; j++)
        sum += memo[i][j];
      q++;
      p--;
    }

    if (type =='S')
      printf("%.1lf\n", sum);
    else
      printf("%.1lf\n", sum/30.0);
}
