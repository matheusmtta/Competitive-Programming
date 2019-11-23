/*
* Cost Cutting
* Uva Online Judge 11727
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int i = 1;
  while(i <= n){
    int vec[3];
    for (int i = 0; i < 3; i++)
      cin >> vec[i];
    sort(vec, vec+3);
    printf("Case %d: %d\n", i, vec[1]);
    i++;
  }
}
