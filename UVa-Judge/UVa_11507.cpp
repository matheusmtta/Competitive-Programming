/*
* Bender B. Rodríguez Problem
* UVa Online Judge 11507
* 21/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

string ans[6]={"+x", "-x", "+y", "-y", "+z", "-z"};

int main(){
  int l;
  while(true){
    cin >> l;
    if (l==0) return 0;
    string move;
    int dir=0;
    for (int i = 1; i < l; i++){
      cin >> move;
      //cout << dir << endl;
      if (move == "No")
        continue;
      else if (move=="+z"){
        if (dir == 0) {dir = 4; continue;}
        else if (dir == 1) {dir = 5; continue;}
        else if (dir == 4) {dir = 1; continue;}
        else if (dir == 5) {dir = 0; continue;} 
      }
      else if (move=="-z"){
        if (dir == 0) {dir = 5; continue;}
        else if (dir == 1) {dir = 4; continue;}
        else if (dir == 4) {dir = 0; continue;}
        else if (dir == 5) {dir = 1; continue;} 
      }
      else if (move=="+y"){
        if (dir == 0) {dir = 2; continue;}
        else if (dir == 1) {dir = 3; continue;}
        else if (dir == 2) {dir = 1; continue;}
        else if (dir == 3) {dir = 0; continue;} 
      }
      else if (move=="-y"){
        if (dir == 0) {dir = 3; continue;}
        else if (dir == 1) {dir = 2; continue;}
        else if (dir == 2) {dir = 0; continue;}
        else if (dir == 3) {dir = 1; continue;} 
      }
    }
    cout << ans[dir] << endl;
  }
  return 0;
}