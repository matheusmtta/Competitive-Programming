#include <bits/stdc++.h>

using namespace std;

int fat(int n){
  if (n == 1) return 1;
  return n * fat(n-1);
}

int main(){
  int n;
  cin >> n;
  int aux = fat(n);
  cout << aux << endl;
}
