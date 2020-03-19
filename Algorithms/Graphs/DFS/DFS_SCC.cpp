 
#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1000000000000
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 10100;

int timer = 0, scc;
int n, m;
vector <bool> stack_member(MAX);
stack <int> st;
vector <int> num(MAX), low(MAX);
vector <int> graph[MAX];
map <int, vector <int>> scclist;

void DFS_SCC(int v){
	st.push(v);
	stack_member[v] = true;
	timer++;
	num[v] = low[v] = timer;
	for(int i = 0; i < graph[v].size(); i++){
		if(num[graph[v][i]] == 0){
			DFS_SCC(graph[v][i]);
			low[v] = min(low[v], low[graph[v][i]]);
		}
		else if (stack_member[graph[v][i]] == true)
			low[v] = min(low[v], low[graph[v][i]]);
	}
	if(num[v] == low[v]){
		scc++; 
		scclist[scc];
		while(st.top() != v){
			scclist[scc].push_back(st.top());
			stack_member[st.top()] = false;
			st.pop();
		}
		scclist[scc].push_back(st.top());
		stack_member[st.top()] = false;
		st.pop();
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i <= n; i++){
		num[i] = 0;
		low[i] = -1;
		graph[i].clear();
		stack_member[i] = 0;
	}

	for (int i = 0; i < m; i++){
		int x, y, p; cin >> x >> y >> p;

		if (p == 1){ //GO
			graph[x].push_back(y);
		}
		else { //COME AND GO
			graph[x].push_back(y);
			graph[y].push_back(x);	
		}
	}

	scc = 0;

	for (int i = 1; i <= n; i++){
		if (!num[i]){
			DFS_SCC(i);
		}
	}	

	cout << scc << endl;
	
	return 0;
}