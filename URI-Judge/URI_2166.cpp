#include <bits/stdc++.h>

using namespace std;

int mtx[13];

int main(){
    double n, x=0, y, z;
    cin >> n;
    while(n--){
      x+=2; x = 1.0/x;
    }
    printf("%.10lf\n", x+1);
    return 0;
}
