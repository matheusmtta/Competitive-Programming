#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
    int n=0;
    cin >> n;
    int x, aux, ans=INF, p;
    for (int i = 0; i < n; i++){
      cin >> x;
      if (ans > x){
        ans = x;
        p = i;
      }
    }
    printf("Menor valor: %d\n", ans);
    printf("Posicao: %d\n", p);
    return 0;
}
