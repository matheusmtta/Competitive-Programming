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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		set <int> ss;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			ss.insert(x);
		}

		cout << ss.size() << endl;
	}

	return 0;
}