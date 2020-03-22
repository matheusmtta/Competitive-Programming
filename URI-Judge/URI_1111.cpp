#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int MAX = 15;

int n;
map <pair<int, int>, vector<int>> mtx;
map <pair<int, int>, int> dist;
map <pair<int, int>, int> visited;

//NORTH: ( 1, 0)
//SOUTH: (-1, 0)
//WEST:  ( 0,-1)
//EAST:  ( 0, 1)

map <int, pair <int, int>> mov;

int BFS(pair<int, int> source, int x1, int y1){
	queue <pair<int,int>> walk;
	
	dist[source] = 0;
	visited[source] = 1;
	walk.push(source);

	while (!walk.empty()){
		pair <int, int> v = walk.front();
		walk.pop();

		if (v.first == x1 && v.second == y1) return dist[v];

		for (int i = 0; i < 4; i++){
			pair <int, int> tmp;
			tmp.first = v.first + mov[i].first;
			tmp.second = v.second + mov[i].second;
			
			if (mtx[v][i] == 1 && visited[tmp] == 0){
				visited[tmp] = 1;
				dist[tmp] = dist[v] + 1;
				walk.push(tmp);
			}
		}
	}
	return -1;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	mov[0] = MP(0,  1);
	mov[1] = MP(0, -1);
	mov[2] = MP(-1, 0);
	mov[3] = MP( 1, 0);

	while (true){
		cin >> n;
	
		if (n == 0) return 0;

		for (int y = n-1; y >= 0; y--){
			for (int x = 0; x < n; x++){
				//cout << "(" << x << " " << y << "): ";
				for (int k = 0; k < 4; k++){
					int z; cin >> z;
					//cout << z << " ";
					mtx[MP(x, y)].push_back(z);
					visited[MP(x, y)] = 0;
					dist[MP(x, y)] = -1;
				}
				//cout << endl;
			}
		}

		int q; cin >> q;

		while (q--){
			int x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;

			int ans = BFS(MP(x0, y0), x1, y1);

			if(ans == -1) cout << "Impossible" << endl;
			else cout << ans << endl;
			
			for (int y = n-1; y >= 0; y--){
				for (int x = 0; x < n; x++){
					visited[MP(x, y)] = 0;
					dist[MP(x, y)] = -1;
				}
			}
		}
		cout << endl;
		mtx.clear();
	}

	return 0;
}