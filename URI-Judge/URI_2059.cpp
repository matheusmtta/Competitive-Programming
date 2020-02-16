#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int p, n, m, r, a, sum;
  cin >> p >> n >> m >> r >> a;
  if ( ( ((n+m)%2 == 0) && (p == 1) ) || ( ((n+m)%2 == 1) && (p == 0) ) ){
    if (a == 1 && r == 1) cout << "Jogador 2 ganha!" << endl;
    else if (a==1 && r==0) cout << "Jogador 1 ganha!" << endl;
    else if (a==0 && r==1) cout << "Jogador 1 ganha!" << endl;
    else if (a==1 && r == 0) cout << "Jogador 1 ganha!" << endl;
    else if (a==0 && r == 0) cout << "Jogador 1 ganha!" << endl;
    //cout << '?' << endl;
  } else {
    if (a == 0 && r == 1) cout << "Jogador 1 ganha!" << endl;
    else cout << "Jogador 2 ganha!" << endl;
  }
  return 0;
}
