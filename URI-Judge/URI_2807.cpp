/*
* Iccanobif
* URI Online Judge 2807
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

long long int memo[40];

long long int fib(int n){
  if (memo[n] == 0) memo[n] = fib(n-1)+fib(n-2);
  return memo[n];
}

int main(){
  long long int n, f;
  cin >> n;
  for (int i = 0; i < n; i++)
    memo[i] = 0;
  //for (int i = 0; i < n; i++)
  //    cout << memo[i] << endl;
  memo[0] = 1;
  memo[1] = 1;
  memo[2] = 2;
  fib(n);
  reverse(memo, memo+n);
  for (int i = 0; i < n; i++){
    if (i != n-1) cout << memo[i] << " ";
    else cout << memo[i] << endl;
  }
}
