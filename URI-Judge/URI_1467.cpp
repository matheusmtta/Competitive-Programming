/*
* Zerinho ou Um
* URI Online Judge 1467
* 24/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

using namespace std;


int main(){
  int x, y, z;
  while(scanf("%d %d %d", &x, &y, &z) != EOF){
    if (x == y && y == z) { cout << "*" << endl; continue;}
    else if (x == y) {cout << "C" << endl; continue;}
    else if (x == z) {cout << "B" << endl; continue;}
    else cout << "A" << endl; continue;
  }
  return 0;
}
