#include <bits/stdc++.h>

using namespace std;

float preco[1006];

int main(){
  //ios_base :: sync_with_stdio(0); cin.tie(0);
  int n, x, sum=0, k=1, aux, m, aux2=0;
  while(scanf("%d", &n) != EOF){
    aux2=0;
    int i = 0;
    m = n+1;
    aux = ((m*(m-1))/2) + 1;
    if(n == 0) cout << "Caso " << k << ": " << 1 << " numero" << endl;
    else cout << "Caso " << k << ": " << aux << " numeros" << endl;
    while (i <= n){
      if (i == 0) {cout << 0; if (n != 0) cout << " "; aux2++;}
      if (i == 1) {cout << 1; if (n != 1) cout << " "; aux2++;}
      else {
        for (int j = 0; j < i; j++){
          cout << i;
          aux2++;
          if (aux2 != aux) cout << " ";
        }
      }
      i++;
    }
    k++;
    cout << endl << endl;
  }
}
