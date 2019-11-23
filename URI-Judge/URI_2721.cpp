/*
* Indecisão das Renas
* URI Online Judge 2721
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int x=0, ans=0;
  for (int i =0; i < 9; i++){
    cin >> x;
    ans+=x;
  }
  //cout << ans << endl;
  //cout << ans%9 << endl;
  if (ans%9==1) cout << "Dasher" << endl;
  else if (ans%9==2) cout << "Dancer" << endl;
  else if (ans%9==3) cout << "Prancer" << endl;
  else if (ans%9==4) cout << "Vixen" << endl;
  else if (ans%9==5) cout << "Comet" << endl;
  else if (ans%9==6) cout << "Cupid" << endl;
  else if (ans%9==7) cout << "Donner" << endl;
  else if (ans%9==8) cout << "Blitzen" << endl;
  else if (ans%9==0) cout << "Rudolph" << endl;
  return 0;
}
