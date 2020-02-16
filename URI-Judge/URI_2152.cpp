#include <bits/stdc++.h>

using namespace std;

int mtx[13];

int main(){
    int n, x, y, z;
    cin >> n;
    while(n--){
      cin >> x >> y >> z;
      if (x < 10 && y >= 10) printf("0%d:%d ", x, y);
      else if (y < 10 && x >= 10) printf("%d:0%d ", x, y);
      else if (x < 10 && y < 10) printf("0%d:0%d ", x, y);
      else  printf("%d:%d ", x, y);
      if (z == 1) printf("- A porta abriu!\n");
      if (z == 0) printf("- A porta fechou!\n");
    }
    return 0;
}
