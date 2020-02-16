#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=0, cases;
    cin >> cases;
    int sum=0;
    while(cases--){
      cin >> n;
      for (int i = 1; i <= n; i++)
        if (n%i == 0)
          sum+= i;
      if ((sum-n) == n)
        cout << n << " eh perfeito" << endl;
      else
        cout << n << " nao eh perfeito" << endl;
      sum =0;
    }
    return 0;
}
