#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n], aux = -1;
    cin >> x[0];
    for (int i = 1; i < n; i++){
      cin >> x[i];
      if (x[i] > x[i-1] && (aux == 0 || aux == -1)) {aux = 1; continue;}
      else if (x[i] < x[i-1] && (aux == 1 || aux == -1)) {aux = 0; continue;}
      else {aux = -2; continue;}
    }
    (aux == 1 || aux == 0) ? cout << "1" << endl : cout << "0" << endl;
}
