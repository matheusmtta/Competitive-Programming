#include <bits/stdc++.h>

using namespace std;

int main(){
  long long int n, m, sum=0;
  string str;
  while (cin >> str){
    cin >> n;
    for (int i = 0; i < n; i++){
      cin >> m;
      cout << str[m-1];
    }
    cout << endl;
  }
  return 0;
}
