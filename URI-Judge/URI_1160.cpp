#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases, pa, pb;
    double ca, cb, years=0;
    cin >> cases;
    while(cases--){
      cin >> pa >> pb >> ca >> cb;
      while(pa <= pb){
        pa*=((ca/100.0)+1);
        pb*=((cb/100.0)+1);
        years++;
        if (years > 100)
          break;
      }
      if (years > 100)
        cout << "Mais de 1 seculo." << endl;
      else
        cout << years << " anos." << endl;
      years=0;
    }
    return 0;
}
