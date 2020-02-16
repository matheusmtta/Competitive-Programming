#include <bits/stdc++.h>
int main(){
    double i, c, sum=0;
    for(i=1; i<=100; i++){
        c=1/i;
        sum+=c;
    }
    printf("%.2lf\n", sum);
    return 0;
}
