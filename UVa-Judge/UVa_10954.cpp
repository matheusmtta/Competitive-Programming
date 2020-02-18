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


	while (true){
		int n; cin >> n;
		if (n == 0) exit(0);

		priority_queue <int, vector<int>, greater<int> > pq;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			pq.push(x);
		}

		int ans = 0;

		while (pq.size() != 1){
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();

			ans += (x + y);

			pq.push(x+y);
		}

		cout << ans << endl;
	}

	return 0;
}