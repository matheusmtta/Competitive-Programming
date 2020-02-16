#include <bits/stdc++.h>

using namespace std;

int main(){
  int a, n, sum=0;
  cin >> a >> n;
  while (n <= 0)
    cin >> n;
  for (int i = 0; i < n; i++)
    sum+=(a+i);
  cout << sum << endl;
}
