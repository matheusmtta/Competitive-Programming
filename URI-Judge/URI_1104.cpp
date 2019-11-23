/*
* Troca de Cartas
* URI Online Judge 1104
* 02/10/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

int alice[1000001], beatriz[1000001];
int al_ans=0, be_ans=0, ans;

int main(){
  int a, b, x;
  while(1){
    cin >> a >> b;
    if (a == 0 && b == 0) break;
    for (int i = 0; i < a; i++){
      cin >> x;
      alice[x]++;
    }
    for (int i = 0; i < b; i++){
      cin >> x;
      beatriz[x]++;
    }
    for (int i = 1; i < 1000001; i++){
      if (alice[i] > 0 && beatriz[i] == 0) {al_ans++; continue;}
      else if (beatriz[i] > 0 && alice[i] == 0) {be_ans++; continue;}
    }
    cout << min(al_ans, be_ans) << endl;
    for (int i = 0; i < 1000001; i++)
       alice[i] = beatriz[i] = 0;
    al_ans=be_ans=0;
  }
}
