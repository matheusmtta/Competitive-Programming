/*
* Mais Cavalos
* URI Online Judge 2808
* 28/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int move_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int move_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool verify(int x1, int y1, int x2, int y2){
  if (x1 < 0 || x1 > 7) return false;
  if (y1 < 0 || y1 > 7) return false;
  if (x2 < 0 || x2 > 7) return false;
  if (y2 < 0 || y2 > 7) return false;
  for (int i = 0; i < 8; i++)
    if (x1+move_x[i] == x2 && y1+move_y[i] == y2) return true;
  return false;
}

int main(){
  string a, b;
  cin >> a >> b;
  int x2, y2, x1, y1;
  x1 = a[0]-'a';
  x2 = b[0]-'a';
  y1 = a[1]-'1';
  y2 = b[1]-'1';
  (verify(x1, y1, x2, y2)) ? cout << "VALIDO" << endl : cout << "INVALIDO" << endl;
}
