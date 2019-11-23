/*
* Fuga do Cavalo
* URI Online Judge 1147
* 05/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int move_x[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int move_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool verify(int x1, int y1){
  if (x1 < 0 || x1 > 7) return false;
  if (y1 < 0 || y1 > 7) return false;
  return true;
}

int main(){
  int count = 1;
  while(1){
    string pos, var;
    cin >> pos;
    if (pos == "0") return 0;
    int x, y, ans=8, w, s;
    int mtx[8][8];
    x = abs(pos[0]-'8');
    y = pos[1]-'a';
    //cout << x << " " << y << endl;
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        mtx[i][j] = 0;
      }
    }
    for (int i = 0; i < 8; i++){
      cin >> var;
      w = abs(var[0]-'8');
      s = var[1]-'a';
      if (verify(w, s))
        mtx[w][s]=5;
    }

    mtx[x][y] = 8;

    // for (int i = 0; i < 8; i++){
    //   for (int j = 0; j < 8; j++){
    //     cout << mtx[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < 8; i++){
      if (verify(x+move_x[i], y+move_y[i])){
        int x_aux = x+move_x[i];
        int y_aux = y+move_y[i];
        bool aux_1 = ((verify(x_aux-1, y_aux-1) && mtx[x_aux-1][y_aux-1]==5));
        bool aux_2 = ((verify(x_aux-1, y_aux+1) && mtx[x_aux-1][y_aux+1]==5));
        if (aux_1 || aux_2) ans-=1;
      }
      else ans--;
    }
    printf("Caso de Teste #%d: %d movimento(s).\n", count, ans);
    ans=8;
    count++;
  }
}
