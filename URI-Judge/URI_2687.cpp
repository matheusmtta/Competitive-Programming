/*
* Dominação Bacteriana
* URI Online Judge 2687
* 26/09/2019
* matheusmtta (Matheus Motta)
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int mtx[15][15], resp=0;
int n, inputs, visited[225];
vector <int> graph[225];

bool allow(int i, int j){
  if (i < 0 || i > n-1) return false;
  if (j < 0 || j > n-1) return false;
  if (mtx[i][j]==1) return false;
  return true;
}

int def_adj(){
  int ones=0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int u = (i+j)+i*(n-1);
      //cout << "Vertice: " << u << " " << mtx[i][j] << endl;
      if (!mtx[i][j]){
        if (allow(i+1, j)) graph[u].push_back((i+1+j)+(i+1)*(n-1));
        if (allow(i-1, j)) graph[u].push_back((i-1+j)+(i-1)*(n-1));
        if (allow(i, j+1)) graph[u].push_back((i+j+1)+(i)*(n-1));
        if (allow(i, j-1)) graph[u].push_back((i+j-1)+(i)*(n-1));
      }
      else {ones++; visited[u]=1;}
    }
    //cout << endl;
  }
  return ones;
}

void DFS(int v){
  if (v < n || v%n==0 || (v+1)%n==0 || v+n >= n*n) resp-=500;
  resp++;
  visited[v] = 1;
  for (int i = 0; i < graph[v].size(); i++){
    if (!visited[graph[v][i]]) {
      DFS(graph[v][i]);
    }
  }
}

int main(){
  cin >> inputs;
  while(inputs--){
    cin >> n;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        cin >> mtx[i][j];
      }
    }

    int perimetro = def_adj();
    // for (int i = 0; i < n*n; i++){
    //   cout << i << " ";
    //   for (int j = 0; j < graph[i].size(); j++){
    //     cout  << graph[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    for (int i = 0; i < n*n; i++){
      if (!visited[i]) DFS(i);
      if (resp > 0) {
        perimetro+=resp;
        //cout << resp << endl;
      }
      resp=0;
    }
    float ans=(float)perimetro/2;
    printf("%.2f\n", ans);

    for (int i = 0; i < n*n; i++) {
      visited[i] = 0;
      graph[i].clear();
    }
  }
}
