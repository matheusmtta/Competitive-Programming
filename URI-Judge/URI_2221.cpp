#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    while(n--){
      int bonus, atkA, atkB, defA, defB, LvA, LvB;
      cin >> bonus;
      cin >> atkA >> defA >> LvA;
      cin >> atkB >> defB >> LvB;
      float vga, vgb;
      if (LvA%2 == 0) {vga = ((atkA+defA)/2)+bonus;}
      else {vga = ((atkA+defA)/2);}
      if (LvB%2 == 0) {vgb = ((atkB+defB)/2)+bonus;}
      else {vgb = ((atkB+defB)/2);}
      if (vga == vgb) {cout << "Empate" << endl; continue;}
      else vga > vgb ? cout << "Dabriel" << endl : cout << "Guarte" << endl;
    }
    return 0;
}
