/*
* Save Setu
* Uva Online Judge 12403
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    long long x;
    long long total=0;
    cin >> n;
    while(n--){
      string str;
      cin >> str;
      if (str=="donate") {cin >> x; total+=x;}
      else cout << total << endl;
    }
  return 0;
}
