/*
* Tariff Plan
* UVa Online Judge 12157
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k=1;
  while(n--){
    int q;
    int miles=0, juice=0;
    cin >> q;
    for (int i = 0; i < q; i++){
      int x;
      cin >> x;
      miles+=((1+(x/30))*10);
      juice+=((1+(x/60))*15);
    }
    if (miles < juice) printf("Case %d: Mile %d\n", k, (int)miles);
    else if (miles > juice) printf("Case %d: Juice %d\n", k, (int)juice);
    else if (miles == juice) printf("Case %d: Mile Juice %d\n", k, (int)miles);
    k++;
  }
  return 0;
}
