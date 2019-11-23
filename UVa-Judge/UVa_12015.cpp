/*
* Google is Feeling Lucky
* UVa Online Judge 12015
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k=1;
  while(n--){
    string str;
    int x, maxi=0;
    vector <pair<int, string>> sites;
    for (int i = 0; i < 10; i++){
      cin >> str >> x;
      sites.push_back({x, str});
      maxi = max(maxi, x);
    }
    printf("Case #%d:\n", k);
    for (int i = 0; i < 10; i++){
      if (sites[i].first==maxi)
        cout << sites[i].second << endl;
    }
    k++;
  }
  return 0;
}
