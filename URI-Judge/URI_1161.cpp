/*
* Soma de Fatoriais
* URI Online Judge 1161
* 24/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

using namespace std;


unsigned long long int memo[20];

unsigned long long int fat(unsigned long long int n){
  if (memo[n] == 0) return memo[n] = n*fat(n-1);
  else return memo[n];
}

int main(){
  memo[0] = 1;
  memo[1] = 1;
  memo[2] = 2;
  unsigned long long int n, m, resp;
  while(scanf("%llu %llu", &n, &m) != EOF){
    resp = fat(n)+fat(m);
    printf("%llu\n", resp);
  }
  return 0;
}
