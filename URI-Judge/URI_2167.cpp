#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, a=0, aux = 0, idx=0,x;
    cin >> n;
    for (int i = 0; i < n; i++){
      cin >> x;
      if (x < aux && idx != 1){
        a = i+1;
        idx=1;
      }
      aux = x;
    }
    cout << a << endl;
}
