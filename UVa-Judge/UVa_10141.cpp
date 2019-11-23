/*
* Request for Proposal
* UVa Online Judge 10141
* 18/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, p, r, k=1;
  while(true){
    cin >> n >> p;
    if (n==0 && p==0) return 0;
    double price = INF, curr_p;
    int req=-1, lim;
    string ans, name, tmp;
    for (int i = 0; i < n; i++){
      cin.ignore();
      getline(cin, tmp);
    }
    for (int i = 0; i < p; i++){
      getline(cin, name);
      scanf("%lf %d\n", &curr_p, &lim);
      if (lim > req){
        req = lim;
        ans = name;
        price = curr_p;
      }
      else if (lim == req && curr_p < price){
        req = lim;
        ans = name;
        price = curr_p;
      }
      for (int j = 0; j < lim; j++)
      getline(cin, tmp);
    }
    if (k != 1) cout << endl;
    cout << "RFP #" << k << endl;
    cout << ans << endl;
    k++;
  }
  return 0;
}
