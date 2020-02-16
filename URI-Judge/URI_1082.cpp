#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int help = 0;

void dfs(vector<int> *graph, int *visited, int source, int tabs){
  visited[source] = 1;
  int next = tabs+2;
  int j = tabs;
  for (int i = 0; i < graph[source].size(); i++){
    help = 1;
    if (!visited[graph[source][i]]){
      while(j--) cout << " ";
      cout << source << "-" << graph[source][i] << " pathR(G," << graph[source][i]  << ")" << endl;
      dfs(graph, visited, graph[source][i], next);
      j = tabs;
    }
    else{
      while(j--) cout << " ";
      cout << source << "-" << graph[source][i] << endl;
      j = tabs;
    }
  }
}

int main(){
  int n, e, c, tab=0, x, y, k=1;
  cin >> c;
  while(c--){
    cin >> n >> e;
    vector<int> graph[n];
    int visited[n];
    for (int i = 0; i < n; i++)
      visited[i] = 0;
    for (int i = 0; i < e; i++){
      cin >> x >> y;
      graph[x].push_back(y);
      //graph[y].push_back(x);
    }
    help = 0;
    for (int i = 0; i < n; i++)
      sort(graph[i].begin(), graph[i].end());
    cout << "Caso " << k << ":" << endl;
    for (int i = 0; i < n; i++){
      if(!visited[i]){
        dfs(graph, visited, i, 2);
      }
      if(help == 1) {cout << endl; help = 0;}
    }
    k++;
  }
  return 0;
}
