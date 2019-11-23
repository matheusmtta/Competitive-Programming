/*
* Train Tracks
* UVa Online Judge 11586 
* 21/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    string str;
    int m=0, f=0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++){
      if (str[i]==' ') continue;
      if (str[i]=='M') m++;
      else if (str[i]=='F') f++;
    }
    if (m==1 && f==1) {cout << "NO LOOP" << endl; continue;}
    if (m==f) cout << "LOOP" << endl;
    else cout << "NO LOOP" << endl;
  }
  return 0;
}