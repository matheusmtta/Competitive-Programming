#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

#define MAX_V 200
#define MAX_E 200

typedef long long int int64;
typedef unsigned long long int  uint64;

//COMPUTES MAXIMUM FLOW IN O(VE^2)

int n, m;
int cap[MAX_V][MAX_V];
vector<int> graph[MAX_V];

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && cap[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n

	int s, t;

	cin >> s >> t >> m;
	s--; t--;
	
	for (int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		x--; y--;

		graph[x].push_back(y);
		graph[y].push_back(x);

		cap[x][y] += w;
		cap[y][x] += w;
	}

	cout << maxflow(s, t) << endl;	

	return 0;
}
