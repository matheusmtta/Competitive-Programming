/*
* Presentes Grandes
* URI Online Judge 2720
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair <int, int> &b){
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main(){
  int vol, x, y, z, t, n, k, l;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &k);
    vector <pair <int, int> > presentes;
    vector <int> choices;
    for (int i = 0; i < n; i++){
      scanf("%d %d %d %d", &l,&x,&y,&z);
      presentes.push_back({l, x*y*z});
    }
    sort(presentes.begin(), presentes.end(), sortbysec);
    for (int i = 0; i < k; i++)
      choices.push_back(presentes[i].first);
    sort(choices.begin(), choices.end());
    for (int i = 0; i < k; i++){
      if (i != k-1) printf("%d ", choices[i]);
      else printf("%d\n", choices[i]);
    }
  }
  return 0;
}
