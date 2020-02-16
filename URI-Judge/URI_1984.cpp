#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  string n;
  cin >> n;
  for (int i = n.length()-1; i >= 0; i--)
    cout << n[i];
  cout << endl;
}
