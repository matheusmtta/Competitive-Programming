#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  float a, b, x, y=1, z, sum = 0;
  while (cin >> n){
    for (int i = 0; i < n; i++){
      cin >> a >> b;
      if (i == 0) {y = b/a; cout << '1' << endl; continue;}
      z = b/a;
      if (z > y) {cout << i+1 << endl; y = z;}
    }
  }
  return 0;
}
