#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, k=1;
  while(1){
    cin >> n >> m;
    if (n==0 && m==0) return 0;
    int marbles[n];
    for (int i = 0; i < n; i++)
      cin >> marbles[i];
    int x, aux=0;
    sort(marbles, marbles+n);
    cout << "CASE# " << k << ":" << endl;
    for (int i = 0; i < m; i++){
      cin >> x;
      for (int j = 0; j < n; j++){
        if (x==marbles[j]){
          cout << x << " found at " << j+1 << endl;
          aux=1;
          break;
        }
      }
      if (!aux) cout << x << " not found" << endl;
      aux=0;
    }
    k++;
  }
}
