#include <bits/stdc++.h>

using namespace std;

int mtx[13];

int main(){
    for (int i = 1; i <= 12; i++){
      if (i == 4 || i == 6 || i == 9 || i == 11)
        mtx[i] = 30;
      else mtx[i] = 31;
    }
    mtx[2] = 29;
    mtx[12] = 25;
    int m, d;
    while (scanf("%d %d", &m, &d) != EOF){
      int dias=360, resp=0;
      if (m == 12 && d > 25) {cout << "Ja passou!" << endl; continue;}
      else if (m==12 && d == 25) {cout << "E natal!" << endl; continue;}
      else if (m==12 && d == 24) {cout << "E vespera de natal!" << endl; continue;}
      for (int i = m; i <= 12; i++){
        if (i == m) resp+= mtx[m]-d;
        else resp+= mtx[i];
      }
      cout << "Faltam " << resp << " dias para o natal!" << endl;
    }
    return 0;
}
