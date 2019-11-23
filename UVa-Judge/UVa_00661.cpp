/*
* Blowing Fuses
* UVa Online Judge 00661
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, c, k=1;
  while(1){
    cin >> n >> m >> c;
    if (n==0 && m==0 && c==0) return 0;
    vector <pair <int, bool>> devices;
    bool aux=false;
    for (int i = 0; i < n; i++){
      int x; cin >> x;
      devices.push_back({x, false});
    }
    int amperes=0, ans=0;
    for (int i = 0; i < m; i++){
      int x; cin >> x; x-=1;
      if (devices[x].second==true) {
        amperes-=devices[x].first;
        devices[x].second=false;
      }
      else if (devices[x].second==false) {
        amperes+=devices[x].first;
        devices[x].second=true;
      }
      if (amperes > c) aux=true;
      ans = max(amperes, ans);
    }
    cout << "Sequence " << k << endl;
    if (aux) cout << "Fuse was blown." << endl;
    else {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << ans << " amperes." << endl;
    }
    k++;
    cout << endl;
  }
  return 0;
}
