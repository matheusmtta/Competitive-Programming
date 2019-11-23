/*
* Relational Operators
* Uva Online Judge 11172
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int x, y;
    cin >> x >> y;
    if (x > y) cout << ">" << endl;
    else if (x < y) cout << "<" << endl;
    else cout << "=" << endl;
  }
}
