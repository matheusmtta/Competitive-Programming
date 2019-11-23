/*
* Greedy Gift Givers
* UVa Online Judge 00119
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(1){
    string names[n];
    map <string, int> account;
    for (int i = 0; i < n; i++){
      cin >> names[i];
      account.insert({names[i], 0});
    }
    int money[n];
    for (int i = 0; i < n; i++)
      money[i]=0;
    for (int i = 0; i < n; i++){
      string str; int quant, m;
      cin >> str >> quant >> m;
      if(m != 0)
        account[str]-=m*(quant/m);
      for (int j = 0; j < m; j++){
        string r; cin >> r;
        account[r]+=(quant/m);
      }
    }
    for (int i = 0; i < n; i++){
      cout << names[i] << " " << account[names[i]] << endl;
    }
    if (cin >> n) cout << endl;
    else return 0;
  }
  return 0;
}
