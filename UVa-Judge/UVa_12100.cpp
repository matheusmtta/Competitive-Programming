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

	int t; cin >> t;

	while (t--){
		int n, m; cin >> n >> m;

		vector <int> jobs(10, 0);

		queue <pair <int, bool>> sim;

		for (int i = 0; i < n; i++){
			int x; cin >> x;

			jobs[x] += 1;
			//cout << x << " " << jobs[x] << endl;

			pair <int, bool> tmp;

			tmp.first = x;

			tmp.second = false; 	
			if (i == m) tmp.second = true;

			sim.push(tmp);
		}

		int ans = 0;

		while (true){
		 	pair <int, bool> next = sim.front();
		 	sim.pop();

		 	int aux = next.first;

		 	bool flag = true;

		 	for (int i = 1; i <= 9; i++){
		 		if (i > aux && jobs[i] > 0){
		 			sim.push(next);
		 			flag = false;
		 			break;
		 		}
		 	}

		 	if (!flag) continue;
		 	else {
		 		if (next.second) {cout << ans+1 << endl; break;}
		 		else{
		 			jobs[aux]--;
		 			ans++;
		 		}
		 	}
		}
	}

	return 0;
}