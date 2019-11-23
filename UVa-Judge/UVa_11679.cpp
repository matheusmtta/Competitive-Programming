/*
* Sub Prime
* UVa Online Judge 11679
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  while(1){
    int b, n;
    cin >> b >> n;
    if (b == 0 && n == 0) return 0;
    int vec[b+1];
    for (int i = 1; i <= b; i++)
      cin >> vec[i];
    for (int i = 0; i < n; i++){
      int x, y, z;
      cin >> x >> y >> z;
      vec[x]-=z;
      vec[y]+=z;
    }
    int aux=1;
    for (int i = 1; i <= b; i++){
      if (vec[i] < 0) aux=0;
    }
    if (aux) cout << "S" << endl;
    else cout << "N" << endl;
  }
  return 0;
}
