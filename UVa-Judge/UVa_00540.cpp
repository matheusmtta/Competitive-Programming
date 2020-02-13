#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int scn = 1;
	while (true){
		int q; cin >> q;
		if (q == 0) break;

		queue <int> teams[1005];
		queue <int> mainq;
		int from[1000005];

		for (int t = 0; t < q; t++){
			int n; cin >> n;
			for (int i = 0; i < n; i++){
				int x; cin >> x;
				from[x] = t;
			}
		}

		string cmd;

		cout << "Scenario #" << scn << endl;

		while (true){
			cin >> cmd;
			if (cmd == "STOP") break;
			if (cmd == "ENQUEUE") {
				int k; cin >> k;
				int fr = from[k];

				if (teams[fr].empty()){
					mainq.push(k);
				}

				teams[fr].push(k);
			}
			else {
				int fr = from[mainq.front()];

				cout << teams[fr].front() << endl;
				teams[fr].pop();

				if (teams[fr].empty())
					mainq.pop();
			}
		}
		cout << endl;
		scn++;
	}	

	return 0;
}