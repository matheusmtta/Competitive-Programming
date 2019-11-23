/*
* Álbum da Copa
* URI Online Judge 2779
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  set <int> figurinhas;
  int n, m;
  cin >> n;
  cin >> m;
  int x;
  while(m--){
    cin >> x;
    figurinhas.insert(x);
  }
  cout << n-figurinhas.size() << endl;
  return 0;
}
