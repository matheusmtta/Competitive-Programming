#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int n, p;
  cin >> n >> p;
  string action;
  for (int i = 0; i < p; i++){
    cin >> action;
    if (action == "fechou") n++;
    if (action == "clicou") n--;
  }
  cout << n << endl;
  return 0;
}
