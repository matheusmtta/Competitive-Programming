/*
* The Swallowing Ground
* Uva Online Judge 10963
* 11/07/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  while(n--){
    int col;
    cin >> col;
    int x, y;
    cin >> x >> y;
    int dif = abs(x-y);
    bool ans=true;
    for (int i = 1; i < col; i++){
      cin >> x >> y;
      if (x-y != dif ) ans=false;
    }
    if (ans) cout << "yes" << endl;
    else cout << "no" << endl;
    if (n) cout << endl;
  }

  return 0;
}
