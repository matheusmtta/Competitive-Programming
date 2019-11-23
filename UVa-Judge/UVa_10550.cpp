/*
* Combination Lock
* Uva Online Judge 10550
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, first, second, third;
  while(1){
    cin >> n >> first >> second >> third;
    if (n==0 && first==0 && second==0 && third==0) return 0;
    int ans=0;
    ans+=1080;
    int aux = 9*(((n-first+40)%40) + ((second-first+40)%40) + ((second-third+40)%40));
    ans+=aux;
    cout << ans << endl;
  }

}
