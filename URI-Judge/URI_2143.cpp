#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(1){
      int x;
      cin >> n;
      if (n==0) break;
      for (int i = 0; i < n; i++){
        cin >> x;
        x%2==0 ? cout << (x-1)*2 << endl : cout << ((x-1)*2)+1 << endl;
      }
    }
    return 0;
}
