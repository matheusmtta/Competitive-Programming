#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  double n, x, aux;
  cin >> n >> x;
  aux = ((x/n)-1)*100;
  printf("%.2lf%%\n", aux);
}
