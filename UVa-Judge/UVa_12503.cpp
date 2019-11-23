/*
* Robot Instructions
* UVa Online Judge 12503
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    int q, x=0, m; string str;
    cin >> q;
    int moves[q+1];
    getchar();
    for (int i = 1; i <= q; i++){
      cin >> str;
      if (str=="LEFT") {x--; moves[i]=-1;}
      else if (str=="RIGHT") {x++; moves[i]=1;}
      else if (str=="SAME"){
        cin >> str;
        cin >> m;
        moves[i]=moves[m];
        x+=moves[m];
      }
    }
    cout << x << endl;
  }
  return 0;
}
