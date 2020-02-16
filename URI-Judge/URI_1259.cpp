#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int vec;
  vector <int> pares;
  vector <int> impares;
  for (int i = 0; i < n; i++){
    cin >> vec;
    vec%2==0 ? pares.push_back(vec) : impares.push_back(vec);
  }

  sort(pares.begin(), pares.end());
  sort(impares.begin(), impares.end());
  reverse(impares.begin(), impares.end());
  for (int i = 0; i < pares.size(); i++)
    cout << pares[i] << endl;
  for (int i = 0; i < impares.size(); i++)
    cout << impares[i] << endl;
}
