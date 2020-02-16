#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while (cin >> n){
    if (n == 0) { cout << '0' << endl; continue;}
    cout << log2(n) << endl;
  }
  return 0;
}
