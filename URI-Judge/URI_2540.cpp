#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while (cin >> n){
    int uns=0, x;

    for (int i = 0; i < n; i++){
      cin >> x;
      if (x) uns++;
    }

    if ((uns*1.0)/(n*1.0) >= 2.0/3.0) {cout << "impeachment" << endl; continue;}
    else cout << "acusacao arquivada" << endl;
    uns = 0;
  }
  return 0;
}
