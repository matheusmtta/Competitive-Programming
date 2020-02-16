#include <vector>
#include <iostream>
using namespace std;
int dfs(vector<int> *graph, int *visited, int v){
  int traces=0;
  visited[v] = 1;
  for (int i = 0; i < graph[v].size(); ++i){
    if(!visited[graph[v][i]]){
      traces += dfs(graph, visited, graph[v][i]) + 1;
    }
  }
  return traces;
}

int main(){
  int c, x, y, n, e, source;
  cin >> c;
  while(c--){
    cin >> source;
    cin >> n >> e;
    vector<int> graph[n];
    int visited[n];
    for (int i = 0; i < n; i++)
      visited[i] = 0;
    while(e--){
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    cout << dfs(graph, visited, source)*2 << endl;
  }
}
