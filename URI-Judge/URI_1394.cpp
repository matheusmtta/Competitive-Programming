#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int64 flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int64 cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int64 dfs(int v, int64 pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int64 tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int64 flow() {
        int64 f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int64 pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;

    while (cin >> n >> k >> m){
        if (n == 0 && k == 0 && m == 0) exit(0);
        vector <vector<int>> jogos(n+5, vector <int>(n+5, 0));
        map <pair<int, int>, int> mp;
        vector <int> p(n+5, 0);

        int s, t;
        int node = n, total = 0, a = 0;

        for (int i = 0; i < m; i++){
            int x, y; char r;
            cin >> x >> r >> y;
            if (x == 0 || y == 0) a++;
            if (r == '='){
                p[x]++;
                p[y]++;
            }
            else if (r == '>')
                p[x]+=2;
            else
                p[y]+=2;
            jogos[y][x]++;
            jogos[x][y]++;
        }

        int ans = 0;

        for (int i = 1; i < n; i++){
            for (int j = i+1; j < n; j++){
                mp[{i, j}] = node++;
                ans += 2*(k - jogos[i][j]);
            }
        }

        s = 0, t = node+1;

        Dinic graph(node+2, s, t);

        for (int i = 1; i < n; i++){
            for (int j = i+1; j < n; j++){
                graph.add_edge(i, mp[{i, j}], INF);
                graph.add_edge(j, mp[{i, j}], INF);
                graph.add_edge(mp[{i, j}], t, 2*(k - jogos[i][j]));
            }
        }

        total = (n-1)*k; total -= a; total *= 2; total+=p[0]; total--;
        
        bool flag = false;

        for (int i = 1; i < n; i++){
            if (total < p[i]){
                cout << "N" << endl;
                flag = true;
                break;
            }
        }

        if (flag)
            continue;

        for (int i = 1; i < n; i++){
            graph.add_edge(s, i, total - p[i]);
        }

        int maxflow = graph.flow();

        if (maxflow == ans)
            cout << "Y" << endl;
        else 
            cout << "N" << endl;
    }

    return 0;
}
