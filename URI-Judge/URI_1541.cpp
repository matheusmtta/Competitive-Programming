#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int a=1, b=1, c=1;
  while (1){
    cin >> a;
    if (a == 0) return 0;
    cin >> b >> c;
    if (b == 0 || c == 0) return 0;
    float aux = floor(sqrt(a*b*(100.0/c)));
    printf("%.0f\n", aux);
  }
  return 0;
}
