#include <bits/stdc++.h>

using namespace std;

float preco[1006];

int main(){
  //ios_base :: sync_with_stdio(0); cin.tie(0);
  int n, m, z, t, a, b;
  string times;
  while(scanf("%d:%d", &a, &b) != EOF){
    t = (a*60)+b;
    int k = (8*60)-t;
    if (k > 60) cout << "Atraso maximo: 0" << endl;
    else cout << "Atraso maximo: " << 60-k << endl;
  }
  return 0;
}
