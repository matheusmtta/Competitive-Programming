#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, x, y, z, k=1;
  cin >> n;
  while(n--){
    string op;
    cin >> op;
    cin >> x >> y >> z;
    if (op == "min") {
      int minimo = min(x, y);
      minimo = min(minimo, z);
      cout << "Caso #" << k << ": " << minimo << endl;
      k++;
      continue;
    }
    else if (op == "eye"){
      cout << "Caso #" << k << ": " << (int)((0.30*x)+(0.59*y)+(0.11*z)) << endl;
      k++;
      continue;
    }
    else if (op == "max"){
      int maximo = max(x, y);
      maximo = max(maximo, z);
      cout << "Caso #" << k << ": " << maximo << endl;
      k++;
      continue;
    }
    else if (op == "mean"){
      cout << "Caso #" << k << ": " << (int)((x+y+z)/3) << endl;
      k++;
      continue;
    }
  }
  return 0;
}
