/*
* Event Planning
* Uva Online Judge 11559
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, b, h, w;
  while(scanf("%d %d %d %d", &n, &b, &h, &w)==4){
    int price, beds, ans=b+1;
    for (int i = 0; i < h; i++){
      int aux=0;
      cin >> price;
      for (int j = 0; j < w; j++){
        cin >> beds;
        aux = max(aux, beds);
      }
      if (aux >= n) ans = min(ans, n*price);
    }
    if (ans == b+1) {cout << "stay home" << endl;}
    else cout << ans << endl;
  }
  return 0;
}
