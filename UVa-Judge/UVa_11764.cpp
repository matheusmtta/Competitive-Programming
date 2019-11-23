/*
* Jumping Mario
* UVa Online Judge 11764
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int k = 1;
  while(n--){
    int high=0, low=0;
    int q;
    cin >> q;
    int vec[q];
    cin >> vec[0];
    for (int i = 1; i < q; i++){
      cin >> vec[i];
      if (vec[i] < vec[i-1]) low++;
      else if (vec[i] > vec[i-1]) high++;
    }
    cout << "Case " << k << ": " << high << " " << low << endl;
    k++;
  }
  return 0;
}
