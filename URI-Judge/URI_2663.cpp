#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, m, j=0, count=0;
  cin >> n >> m;
  int comp[n];
  for (int i = 0; i < n; i++) cin >> comp[i];
  sort(comp, comp+n);
  reverse(comp, comp+n);
  j=m;
  count+=m;
  while(comp[m-1] == comp[j]) {
    count++;
    j++;
  }
  cout << count << endl;
  return 0;
}
