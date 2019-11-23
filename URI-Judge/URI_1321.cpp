/*
* Jollo
* URI Online Judge 1321
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;
bool cards[53];

int main(){
  while(1){
    int ans=0;
    vector <int> a, b, c;
    int x;
    for (int i = 1; i <= 52; i++)
      cards[i]=false;
    for (int i = 0; i < 3; i++){
      cin >> x;
      a.push_back(x);
      cards[a[i]] = true;
    }
    for (int i = 0; i < 2; i++){
      cin >> x;
      b.push_back(x);
      cards[b[i]] = true;
    }
    b.push_back(0);
    if (a[0] == b[0]) return 0;
    sort(a.begin(),a.end());
    ans = -1;
    for (int i = 1; i <= 52; i++){
      if(!cards[i]){
        c = b;
        int prince=0, princess=0;
        c[2]=i;
        sort(c.begin(),c.end());
        if (a[0]>c[2]) princess++;
        else prince++;
        if (a[2]>c[1]) princess++;
        else prince++;
        if (a[1]>c[0]) princess++;
        else prince++;
        //cout << prince << " " << princess << endl;
        if (prince >= 2) {ans=i; break;}
      }
    }
    cout << ans << endl;
  }
}
