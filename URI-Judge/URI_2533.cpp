#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while(cin >> n){
    float c[n], nota[n];
    float sum_a=0, sum_b=0;
    for (int i = 0; i < n; i++)
      cin >> nota[i] >> c[i];
    for (int i = 0; i < n; i++){
      sum_a += (nota[i]*c[i]);
      sum_b += c[i];
    }
    printf("%.4f\n", sum_a/(sum_b*100));
  }
  return 0;
}
