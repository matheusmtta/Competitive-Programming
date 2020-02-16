#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  while (cin >> n){
    long long int x[100], y[100], z[100], c;
    char op[100];
    string name[100];
    vector <string> error;
    for (int i = 0; i < n; i++)
      scanf("%llu %llu=%llu", &x[i], &y[i], &z[i]);
    for (int i = 0; i < n; i++){
      cin >> name[i] >> c >> op[i];
      if (op[i] == '*'){
        if (x[c-1] * y[c-1] != z[c-1])
          error.push_back(name[i]);
      }
      else if (op[i] == '+'){
        if (x[c-1] + y[c-1] != z[c-1])
          error.push_back(name[i]);
      }
      else if (op[i] == '-'){
        if (x[c-1] - y[c-1] != z[c-1])
          error.push_back(name[i]);
      }
      else if (op[i] == 'I'){
        if ((x[c-1] - y[c-1] == z[c-1]) || (x[c-1] + y[c-1] == z[c-1]) || (x[c-1] * y[c-1] == z[c-1]))
          error.push_back(name[i]);
      }
    }
    sort(error.begin(), error.end());
    if (error.size() == n) cout << "None Shall Pass!" << endl;
    else if (error.size() == 0) cout << "You Shall All Pass!" << endl;
    else if (error.size() > 0 && error.size() < n){
      for (int it = 0; it != error.size(); it++){
        cout << error[it];
        if (it != error.size()-1) cout << " ";
        else cout << endl;
      }
    }
  }
  return 0;
}
