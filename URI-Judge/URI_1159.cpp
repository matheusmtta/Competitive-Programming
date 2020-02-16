#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=1, sum=0, i=0;
    while (n){
      cin >> n;
      if (n == 0) break;
      while(i < 5){
        if (n%2 == 0){
          i++;
          sum+=n;
        }
        n++;
      }
        cout << sum << endl;
        sum = 0;
        i = 0;
    }
    return 0;
}
