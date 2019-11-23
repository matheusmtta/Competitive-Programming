/*
* Turitas no Parque Huacachina
* URI Online Judge 2708
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int jipes=0, pessoas=0, x;
  string str;
  while(str != "ABEND"){
    cin >> str >> x;
    if (str == "SALIDA") {
      pessoas+=x;
      jipes++;
    }
    else if (str == "VUELTA"){
      pessoas-=x;
      jipes--;
    }
  }
    cout << pessoas << endl <<  jipes << endl;
    return 0;
}
