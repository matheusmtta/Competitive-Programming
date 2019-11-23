/*
* One-Two-Three
* Uva Online Judge 12289
* 11/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n = 0, k=1;
  cin >> n;
  string type;
  string one="one", two="two", three="three";
  while(n--){
    cin >> type;
    int ones=0, twos=0, threes=0;
    if (type.length()==3){
      for (int i = 0; i < 3; i++){
        if (one[i]==type[i]) ones++;
      }
      if (ones >= 2) {cout << 1 << endl; continue;}
      for (int i = 0; i < 3; i++){
        if (two[i]==type[i]) twos++;
      }
      if (twos >= 2) {cout << 2 << endl; continue;}
    }
    else if (type.length()==5){
      for (int i = 0; i < 5; i++){
        if (three[i]==type[i]) threes++;
      }
      if (threes >= 2) {cout << 3 << endl; continue;}
    }
  }
}
