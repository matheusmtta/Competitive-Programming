#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int triangD(int a, int b, int c){
  if (a < b+c && b < a+c && c < a+b) return 1;
  else return 0;
}

int main(){
  int triang[4];
  int aux=0;
  for (int i = 0; i < 4; i++)
    cin >> triang[i];
  aux+=triangD(triang[0], triang[1], triang[2]);
  aux+=triangD(triang[0], triang[1], triang[3]);
  aux+=triangD(triang[0], triang[2], triang[3]);
  aux+=triangD(triang[1], triang[2], triang[3]);

  if (aux) cout << "S" << endl;
  else cout << "N" << endl;
}
