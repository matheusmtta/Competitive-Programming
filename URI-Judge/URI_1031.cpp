/*
* Crise de Energia
* URI Online Judge 1031
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int Find(int n, int k){
  int ans=0;
  for (int i = 1; i < n; i++){
    ans = (ans+k)%i;
  }
  return ans;
}

int main(){
  int n;
  while(1){
    cin >> n;
    int k = 1;
    if (n==0) return 0;
    while (Find(n, k) != 11) k++;
    cout << k << endl;
  }
  return 0;
}
