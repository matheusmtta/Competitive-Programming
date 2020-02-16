#include <bits/stdc++.h>

using namespace std;

int main(){
  while (1){
    int n, b;
    cin >> n >> b;
    if (n == 0 && b == 0) break;
    int aux;
    int balls[b];
    set <int> numbers;
    for (int i = 0; i <= n; i++) numbers.insert(i);
    for (int i  = 0; i < b; i++) cin >> balls[i];
    for (int i = 0; i < b; i++){
      for (int j = 0; j < b; j++){
        aux = abs(balls[i]-balls[j]);
        numbers.erase(aux);
      }
    }
    if (numbers.empty()) cout << 'Y' << endl;
    else cout << 'N' << endl;
  }
}
