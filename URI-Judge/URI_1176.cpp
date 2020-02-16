#include <bits/stdc++.h>

using namespace std;

unsigned long long memo[61];

unsigned long long fib(unsigned long long m){
  if (memo[m] == -1) memo[m] = fib(m-1) + fib(m-2);
  return memo[m];
}

int main(){
  unsigned long long int n, m;
  for (int i = 0; i < 61; i++)
    memo[i] = -1;
  memo[0] = 0;
  memo[1] = 1;
  cin >> n;
  while(n--){
    scanf("%lli", &m);
    unsigned long long x = fib(m);
    printf("Fib(%lli) = %lli\n", m, x);
  }
}
