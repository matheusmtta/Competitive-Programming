#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x;
  while(cin >> n){
    int vec[n];
    string comida;
    map <int, string> var;
    for (int i = 0; i < n; i++){
      cin >> comida >> vec[i];
      var.insert({vec[i], comida});
    }
    sort(vec, vec+n);
    for (int i = 0; i < n; i++){
      cout << var[vec[i]];
      if (i != n-1) cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
