#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=0, cases;
    float aux;
    cin >> cases;
    int sum=0;
    while(cases--){
      cin >> n;
      aux = sqrt(n*1.0);
      for (int i = 1; i <= aux; i++)
        if (n%i == 0)
          sum++;
      if (sum==1)
        cout << n << " eh primo" << endl;
      else
        cout << n << " nao eh primo" << endl;
      sum =0;
    }
    return 0;
}
