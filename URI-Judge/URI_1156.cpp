#include <bits/stdc++.h>
int main(){
    double i, c, sum=0, j=1;
    for(i=1; j<=39; i*=2){
        c=j/i;
        j+=2;
        sum+=c;
    }
    printf("%.2lf\n", sum);
    return 0;
}
