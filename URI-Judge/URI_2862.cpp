/*
* Inseto!
* URI Online Judge 2862
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int x; cin >> x;
    x > 8000 ? cout << "Mais de 8000!" << endl : cout << "Inseto!" << endl;
  }
}
