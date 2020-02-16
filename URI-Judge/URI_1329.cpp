#include <bits/stdc++.h>

using namespace std;

int main(){

  int n=0, i=0;
  while(1){
    cin >> n;
    if (n == 0) break;
    int x, j=0, m=0;
    j=0; m=0;
    for (i = 0; i < n; ++i){
      cin >> x;
      if (x == 0) m++;
      else if (x == 1) j++;
    }
    cout << "Mary won " << m << " times and John won " << j << " times" << endl;
  }
}