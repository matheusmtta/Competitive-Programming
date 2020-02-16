#include <bits/stdc++.h>

using namespace std;

const int MAX = 46;
int memo[MAX];

int fib(int n){
  if (memo[n] == -1) memo[n] = fib(n-1) + fib(n-2);
  return memo[n];
}

int main(){
  int n;
  for (int i = 0; i < MAX; i++)
    memo[i] = -1;
  memo[0] = 0;
  memo[1] = 1;
  cin >> n;
  int aux = fib(n);
  for (int i = 0; i < n-1; i++)
    cout << memo[i] << " ";
  cout << memo[n-1] << endl;
}
