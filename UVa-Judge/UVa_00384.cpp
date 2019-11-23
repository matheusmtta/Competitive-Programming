/*
* Slurpy
* Uva Online Judge 384
* 11/07/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int idx=0;

bool checkSlump(string str){
  if (str[idx] == 'E' || str[idx] == 'D'){
    if (str[idx+1] == 'F'){
      idx+=1;
      while (str[idx] == 'F') idx+=1;
      if (str[idx] == 'G') return true;
      else if (str[idx] == 'E' || str[idx] == 'D'){
        if (checkSlump(str)) return true;
        else return false;
      }
      else return false;
    }
  }
  return false;
}

bool checkSlimp(string str){
  if (str[idx]=='A'){
    if(str[idx+1]=='H'){
      idx+=1;
      return true;
    }
    else if (str[idx+1] == 'B'){
      idx+=2;
      if (checkSlimp(str)){
        if (str[idx+1] == 'C') {
          idx+=1;
          return true;
        }
        else return false;
      }
      else return false;
    }
    else if (str[idx+1] == 'E' || str[idx+1] == 'D'){
      idx+=1;
      if (checkSlump(str)) {
        if (str[idx+1] == 'C') {
          idx+=1;
          return true;
        }
        else return false;
      }
      else return false;
    }
    else return false;
  }
  else{
    return false;
  }
}


bool checkSlurpy(string str){
  bool TSlimp = checkSlimp(str);
  //cout << TSlimp << " " << idx << endl;
  idx+=1;
  bool TSlump = checkSlump(str);
  //cout << TSlump << endl
  idx+=1;
  if (TSlimp && TSlump && idx == str.length()) return true;
  else return false;
}

int main(){
  string str;
  int n;
  cin >> n;
  cout << "SLURPYS OUTPUT" << endl;
  while(n--){
    cin >> str;
    if (checkSlurpy(str)) cout << "YES" << endl;
    else cout << "NO" << endl;
    idx = 0;
  }
  cout << "END OF OUTPUT" << endl;
}
