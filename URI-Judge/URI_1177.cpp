#include <bits/stdc++.h>

using namespace std;

int main(){
    int vec[1000], j=0, n;
    cin >> n;
    for (int i = 0; i < 1000; i++){
      if (j == n) j=0;
      printf("N[%d] = %d\n", i, j);
      j++;
    }
    return 0;
}
