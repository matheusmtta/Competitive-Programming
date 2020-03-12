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

const int MAX = 10010;

vector <int> graph[MAX];
vector <int> visited(MAX);

double dist(double a, double b, double a1, double b1){
	return sqrt(pow(a-a1, 2)+pow(b-b1, 2));
}

map <int, pair <double, pair <double, double> > > coord;


void DFS(int s){
	visited[s] = 1;

	for (int i = 0; i < graph[s].size(); i++){
		if (!visited[graph[s][i]])
			DFS(graph[s][i]);
	}
}


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, R; cin >> M >> N >> R;

	for (int i = 4; i < R+4; i++){
		double x, y, s; cin >> x >> y >> s;
		coord[i] = MP(s, MP(x, y));
		for (int j = 4; j < i; j++){
			double x1 = coord[j].second.first;
			double y1 = coord[j].second.second;
			double ds = dist(x, y, x1, y1);
			double rr = coord[j].first;
			if (dist(x, y, x1, y1) <= (s+rr)){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}

		if (x+s >= M){
			graph[i].push_back(0);
			graph[0].push_back(i);
		}
		if (x-s <= 0){
			graph[i].push_back(1);
			graph[1].push_back(i);
		}
		if (y+s >= N){
			graph[i].push_back(2);
			graph[2].push_back(i);
		}
		if (y-s <= 0){
			graph[i].push_back(3);
			graph[3].push_back(i);
		}
	}

	bool ans = true;

	DFS(0);
	if ((visited[0] && visited[1]) || (visited[0] && visited[2])) ans = false;
	for (int i = 0; i < MAX; i++)
		visited[i] = 0;
	DFS(3);
	if ((visited[3] && visited[4]) || (visited[2] && visited[3])) ans = false;

	if (ans) cout << 'S' << endl;
	else cout << 'N' << endl;

	return 0;
}