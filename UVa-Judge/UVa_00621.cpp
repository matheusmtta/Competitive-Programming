/*
* Secret Research
* Uva Online Judge 00621
* 11/07/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){
    string S[3]={"1", "4", "78"};
    string str;
    cin >> str;
    if (str==S[0] || str==S[1] || str==S[2]) {cout << "+" << endl; continue;}
    else if (str[str.length()-1]=='5' && str[str.length()-2]=='3') {cout << "-" << endl; continue;}
    else if (str[0]=='9' && str[str.length()-1]=='4') {cout << "*" << endl; continue;}
    else cout << '?' << endl;
  }
  return 0;
}
