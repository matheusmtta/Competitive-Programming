#include <bits/stdc++.h>

using namespace std;

float preco[1006];

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  int n, x, sum=0;
  cin >> n;
  for (int i = 0; i < 5; i++){
    cin >> x;
    if (x == n) sum+=1;
  }
  cout << sum << endl;
  return 0;
}
