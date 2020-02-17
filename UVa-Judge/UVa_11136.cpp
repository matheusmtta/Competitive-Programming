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

	int t;

	while (true){
		cin >> t;
		if (t == 0) return 0;
		int64 sum = 0;
		int64 spt = 0;
		multiset <int, greater <int>> ms;

		bool flag = true;

		for (int i = 0; i < t; i++){
			int k; cin >> k;

			for (int j = 0; j < k; j++){
				int x; cin >> x;
				ms.insert(x);
			}

			multiset <int, greater <int>>::iterator it = ms.begin();
			multiset <int, greater <int>>::iterator jt = ms.end();
			jt--;
			
			spt += (*it - *jt);

			ms.erase(jt);
			ms.erase(it);
		}

		cout << spt << endl;
	}

	return 0;
}