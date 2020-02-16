#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (n == 0) cout << "E";
  else if (n >= 1 && n <= 35) cout << "D";
  else if (n >= 36 && n <= 60) cout << "C";
  else if (n >= 61 && n <= 85) cout << "B";
  else if (n >= 86 && n <= 100) cout << "A";
  cout << endl;
  return 0;
}
