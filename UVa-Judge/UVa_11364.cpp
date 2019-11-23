/*
* Parking
* Uva Online Judge 11364
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int x;
    cin >> x; int vec[x];
    for (int i = 0; i < x; i++) cin >> vec[i];
    int maxi=-1, mini=100;
    for (int i = 0; i < x; i++){
      maxi=max(maxi, vec[i]);
      mini=min(mini, vec[i]);
    }
    cout << 2*(maxi-mini) << endl;
  }
}
