#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> par;
    vector <int> impar;
    int n = 0;
    for (int i = 0; i < 15; i++){
      cin >> n;
      if (n%2 == 0)
        par.push_back(n);
      else
        impar.push_back(n);
      if (par.size() == 5){
        for (int i = 0; i < 5; i++)
          printf("par[%d] = %d\n", i, par[i]);
        par.clear();
      }
      if (impar.size() ==5){
        for (int i = 0; i < 5; i++)
          printf("impar[%d] = %d\n", i, impar[i]);
        impar.clear();
      }
    }
    if (impar.size() > 0)
      for (int i = 0; i < impar.size(); i++)
        printf("impar[%d] = %d\n", i, impar[i]);

    if (par.size() > 0)
      for (int i = 0; i < par.size(); i++)
        printf("par[%d] = %d\n", i, par[i]);

    return 0;
}
