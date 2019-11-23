/*
* Lumberjack Sequencing
* UVa Online Judge 11942
* 13/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cout << "Lumberjacks:" << endl;
  while(n--){
    int vec[10], a=1, b=1;
    cin >> vec[0];
    for (int i = 1; i < 10; i++){
      cin >> vec[i];
      if (vec[i] > vec[i-1]) a++;
      else if (vec[i] < vec[i-1]) b++;
    }
    if (a==10 || b==10) cout << "Ordered" << endl;
    else cout << "Unordered" << endl;
  }
  return 0;
}
