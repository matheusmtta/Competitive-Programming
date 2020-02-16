#include <bits/stdc++.h>

using namespace std;

int main(){
  float n;
  cin >> n;
  float sum=0, m=0, me=0, count = 1;
  if (n < 0){
    cout << me << endl;
    return 0;
  }
  sum+=n;
  while (1){
    cin >> n;
    if (n < 0) break;
    count++;
    sum+=n;
  }
  printf("%.2f\n", sum/count);
}
