#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  long long int x, y, z;
  string name1, name2, win, sidea, sideb;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> name1 >> sidea >> name2 >> sideb;
    cin >> x >> y;
    z=x+y;
    if (z%2==0){
      if (sidea == "PAR") cout << name1 << endl;
      else cout << name2 << endl;
    }
    else{
      if (sidea == "IMPAR") cout << name1 << endl;
      else cout << name2 << endl;
    }
  }
}
