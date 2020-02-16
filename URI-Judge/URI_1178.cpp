#include <bits/stdc++.h>

using namespace std;

int main(){
    double vec[100], n;
    cin >> n;
    for (int i = 0; i < 100; i++){
      printf("N[%d] = %.4lf\n", i, n);
      n/=2;
    }
    return 0;
}
