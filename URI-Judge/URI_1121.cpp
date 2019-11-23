/*
* Robô Colecionador
* URI Online Judge 1121
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k, curr_j, curr_i, ans=0;
char pos, cmd, mtx[100][100];

bool allow(int x, int y, char c){
  if (c == '#') return false;
  else if (x < 0 || x > n-1) return false;
  else if (y < 0 || y > m-1) return false;
  return true;
}

int main(){
  while(1){
    cin >> n >> m >> k;
    if (n==0 && m==0 && k==0) return 0;
    for (int i = 0; i < n; i++){
      for (int j= 0; j < m;j++){
        cin >> mtx[i][j];
        if (mtx[i][j] >= 65 && mtx[i][j] <= 90){
          pos = mtx[i][j];
          curr_i = i;
          curr_j = j;
        }
      }
    }
    int move;
    if (pos == 'N') move = 0;
    else if (pos == 'L') move = 1;
    else if (pos == 'S') move = 2;
    else if (pos == 'O') move = 3;
    for (int i = 0; i < k; i++){
      cin >> cmd;
      if (cmd == 'D') {move=(move+1)%4; continue;}
      else if (cmd == 'E') {move=(move+3)%4; continue;}
      else if (cmd == 'F') {
        if (move == 0){
          if (allow(curr_i-1, curr_j, mtx[curr_i-1][curr_j])){//N
            curr_i-=1;
            if (mtx[curr_i][curr_j] == '*') {ans+=1; mtx[curr_i][curr_j] = '.';}
            continue;
          }
          else continue;
        }
        else if (move == 1){
          if (allow(curr_i, curr_j+1, mtx[curr_i][curr_j+1])){//L
            curr_j+=1;
            if (mtx[curr_i][curr_j] == '*') {ans+=1; mtx[curr_i][curr_j] = '.';}
            continue;
          }
        }
        else if (move == 2){
          if (allow(curr_i+1, curr_j, mtx[curr_i+1][curr_j])){//S
            curr_i+=1;
            if (mtx[curr_i][curr_j] == '*') {ans+=1; mtx[curr_i][curr_j] = '.';}
            continue;
          }
        }
        else if (move == 3){
          if (allow(curr_i, curr_j-1, mtx[curr_i][curr_j-1])){//O
            curr_j-=1;
            if (mtx[curr_i][curr_j] == '*') {ans+=1; mtx[curr_i][curr_j] = '.';}
            continue;
          }
        }
      }
    }
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}
