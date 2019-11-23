/*
* Laércio
* URI Online Judge 2812
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, aux=0, x;
  cin >> n;
  while(n--){
    vector <int> total;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
      cin >> x;
      if (x%2==1) total.push_back(x);
    }
    sort(total.begin(), total.end());
    int j = total.size()-1, k =0;
    for (int i = 0; i < total.size(); i++){
      if (i%2==0) {cout << total[j]; j--;}
      else {cout << total[k]; k++;}
      if (i != total.size()-1) cout << " ";
    }
    cout << endl;
  }
}
