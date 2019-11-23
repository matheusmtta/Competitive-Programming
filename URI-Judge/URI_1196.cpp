/*
* WERTYU
* URI Online Judge 1196
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  string ans="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  string str;
  while(getline(cin, str)){
    for (int i = 0; i < str.length(); i++){
      if (str[i] == ' ') cout << ' ';
      else
        for (int j = 0; j < ans.length(); j++)
          if (ans[j] == str[i]) cout << ans[j-1];
    }
    cout << endl;
  }
  return 0;
}
