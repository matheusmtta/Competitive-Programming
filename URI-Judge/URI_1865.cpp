#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  string name;
  int n, power;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> name >> power;
    if (name == "Thor") cout << "Y" << endl;
    else cout << "N" << endl;
  }
}
