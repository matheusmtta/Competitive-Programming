#include <bits/stdc++.h>

using namespace std;

vector < set<int> > scc;
set <int> aux;

void dfs(vector <int> *graph, int v, int *visited){
  visited[v] = 1;
  for (int i = 0; i < graph[v].size(); i++){
    if (!visited[graph[v][i]])
      dfs(graph, graph[v][i], visited);
  }
  aux.insert(v);
}


int main(){
  int l = 0;
  int n, m, q, x, y, k=0;
  while(scanf("%d %d %d", &n, &m, &q) != EOF){
    if (k) printf("\n");
    k = 1;
    vector <int> graph[n+1];
    for (int i = 0; i < m; i++){
      scanf("%d %d", &x, &y);
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    int visited[n+1];
    for (int i = 1; i <= n; i++) visited[i] = 0;
    for (int i = 1; i <= n; i++){
      if (visited[i] == 0) {
        dfs(graph, i, visited);
        //set<int>::iterator it;
        //for (it=aux.begin(); it != aux.end(); it++)
        //  cout << *it << ",";
        //cout << endl;
        scc.push_back(aux);
        aux.clear();
      }
    }
    int aux2 = 0;
    for (int i = 0; i < q; i++){
      scanf("%d %d", &x, &y);
      for (int j = 0; j < scc.size(); j++){
        if (scc[j].count(x) && scc[j].count(y)) {aux2 = 1; break;}
      }
      if (aux2) printf("S\n");
      else printf("N\n");
      aux2 = 0;
    }
    scc.clear();
    aux.clear();
  }

  return 0;
}
