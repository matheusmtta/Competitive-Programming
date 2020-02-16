#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
  int n, i = 1;
  cin >> n;
  while (i <= n) {
    string sheldon, raj;
    cin >> sheldon;
    cin >> raj;
    int s = 2;
    if (sheldon == raj) {
      printf("Caso #%d: De novo!\n", i);
       i++;
       continue;
     }
    else if (sheldon == "tesoura" && (raj == "papel" || raj == "lagarto")) s = 1;
    else if (sheldon == "papel" && (raj == "pedra" || raj == "Spock")) s = 1;
    else if (sheldon == "pedra" && (raj == "lagarto" || raj == "tesoura")) s = 1;
    else if (sheldon == "lagarto" && (raj == "Spock" || raj == "papel")) s = 1;
    else if (sheldon == "Spock" && (raj == "tesoura" || raj == "pedra")) s = 1;
    else s = 0;

    if (s == 1) printf("Caso #%d: Bazinga!\n", i);
    else if (s == 0) printf("Caso #%d: Raj trapaceou!\n", i);
    i++;
  }

  return 0;
}
