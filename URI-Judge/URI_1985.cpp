#include <bits/stdc++.h>

using namespace std;

float preco[1006];

int main(){
  ios_base :: sync_with_stdio(0); cin.tie(0);
  float n, sum=0, x;
  int index;
  preco[1001] = 1.50;
  preco[1002] = 2.50;
  preco[1003] = 3.50;
  preco[1004] = 4.50;
  preco[1005] = 5.50;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> index >> x;
    sum+=(preco[index]*x);
  }
  printf("%.2f\n", sum);
  return 0;
}
