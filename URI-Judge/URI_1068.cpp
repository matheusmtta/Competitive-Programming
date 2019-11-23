/*
* Balanço de Parênteses I
* URI Online Judge 1068
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int func(string str, int idx, int brakets){
  if (idx >= str.length()) return brakets;
  if (brakets < 0) return brakets;
  if (str[idx] == '(') return func(str, idx+1, brakets+1);
  if (str[idx] == ')') return func(str, idx+1, brakets-1);
  else return func(str, idx+1, brakets);
  return brakets;
}

int main(){
  string n;
  while(cin >> n){
    if (func(n, 0, 0) == 0) cout << "correct" << endl;
    else cout << "incorrect" << endl;
  }
  return 0;
}
