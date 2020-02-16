#include <bits/stdc++.h>

using namespace std;

int visited[26];
vector <int> graph[26];

int dfs(int u, int v){
  //cout << "vertice u: " << u << " | " << "vertice v: " << v << endl;
  visited[u] = 1;
  if (u == v) return 1;
  for (int i = 0; i < graph[u].size(); i++){
    if (!visited[graph[u][i]]){
      if(dfs(graph[u][i], v)) return 1;
    }
  }
  return 0;
}

int main(){
  int m, palavras, count=0, aux=0;
  cin >> m >> palavras;
  string a, b;
  char x, y;
  for (int i = 0; i < m; i++){
    cin >> x >> y;
    graph[x-97].push_back(y-97);
  }
  for (int i = 0; i < palavras; i++){
    cin >> a >> b;
    count = 0;
    if (a.length() != b.length()) {cout << "no" << endl; continue;}
    for (int j = 0; j < a.length(); j++){
      aux = dfs((a[j]-97), (b[j]-97));
      //cout << "result: " << count << endl;
      if (aux) count+=1;
      for (int k = 0; k < 26; k++) visited[k] = 0;
    }
    //cout << count << " " << a.length();
    count == a.length() ? cout << "yes" << endl : cout << "no" << endl;
  }
  return 0;
}
