#include <bits/stdc++.h>

using namespace std;

int batalha(string a, string b){
  if (a == "pedra" && b == "tesoura") return 1;
  else if (a == "tesoura" && b == "papel") return 1;
  else if (a == "papel" && b == "pedra") return 1;
  else if (a == b) return 0;
  else return 0;
}

int main(){
  string x, y, z;
  while(cin >> x >> y >> z){
    int a=0, b=0, c=0;
    a+=batalha(x, y);
    a+=batalha(x, z);
    b+=batalha(y, x);
    b+=batalha(y, z);
    c+=batalha(z, x);
    c+=batalha(z, y);
    if (a > b && a > c) cout << "Os atributos dos monstros vao ser inteligencia, sabedoria..." << endl;
    else if (b > a && b > c) cout << "Iron Maiden's gonna get you, no matter how far!" << endl;
    else if (c > a && c > b) cout << "Urano perdeu algo muito precioso..." << endl;
    else cout << "Putz vei, o Leo ta demorando muito pra jogar..." << endl;
  }
  return 0;
}
