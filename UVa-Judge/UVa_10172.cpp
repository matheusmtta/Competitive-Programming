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
		int N, S, Q;
		cin >> N >> S >> Q;
		//number of stations --- N
		//carrier limit      --- S
		//queue limit        --- Q

		queue <int> bst[N];
		stack <int> carrier;

		for (int i = 0; i < N; i++){
			int l; cin >> l;
			for (int j = 0; j < l; j++){
				int k; cin >> k;
				bst[i].push(k);
			}
		}

		int idx = 0;
		int ans = 0;

		while (true){
			while (!carrier.empty() && (bst[idx].size() != Q || carrier.top() == idx+1)){
				if (carrier.top() != idx+1){
					int aux = carrier.top();
					bst[idx].push(aux);
				}
				ans++;
				carrier.pop();
			}

			while (carrier.size() < S && !bst[idx].empty()){
				int aux = bst[idx].front();
				bst[idx].pop();
				carrier.push(aux);
				ans++;
			}

			bool rsp = true;

			for (int i = 0; i < N; i++){
				if (!bst[i].empty()) rsp = false;
			}
			if (!carrier.empty()) rsp = false;
			if (rsp) break;

			ans += 2;
			idx++;
			if (idx == N) idx = 0; 
		}

		cout << ans << endl;
	}

	return 0;
}