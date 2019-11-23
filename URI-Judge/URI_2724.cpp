/*
* Ajude Patatatitu
* URI Online Judge 2724
* 27/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

bool identify(string a, string b){
  int M = a.length();
  int N = b.length();
  if (M < N) return false;
  for (int i = 0; i <= M-N; i++){
    int j;
    for (j = 0; j < N; j++)
      if (a[i+j] != b[j])
        break;
    if (j == N && ((i+j >= M) || (a[i+j+1]>=65 && a[i+j+1] <=90))   ) return true;
  }
  return false;
}

int main(){
  int n, compostos, m, aux=0;
  scanf("%d", &n);
  getchar();
  while(n--){
    cin >> m;
    string perigos[m];
    for (int i = 0; i < m; i++){
      cin >> perigos[i];
    }
    cin >> compostos;
    for (int i = 0; i < compostos; i++){
      string str;
      cin >> str;
      for (int j = 0; j < m; j++){
        if (identify(str, perigos[j]) && aux==0) {
          cout << "Abortar" << endl;
          aux = 1;
          break;
        }
      }
      if (!aux) cout << "Prossiga" << endl;
      aux=0;
    }
    if (n != 0) cout << endl;
  }
  return 0;
}
