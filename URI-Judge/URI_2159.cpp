#include <bits/stdc++.h>

using namespace std;

int mtx[13];

int main(){
    double n, x, y, z;
    cin >> n;
    x = n*(1/log(n));
    y = 1.25506*n*(1/log(n));
    printf("%.1f %.1f\n", x, y);
    return 0;
}
