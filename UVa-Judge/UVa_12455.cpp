#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vector <int> basis;
vector <int> ans;

void build(int sum, int idx){
	ans.push_back(sum);

	for (int i = idx; i < basis.size(); i++){
		sum += basis[i];
		build(sum, i+1);
		sum -= basis[i];
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int k; cin >> k;
		int n; cin >> n;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			basis.push_back(x);
		}

		build(0, 0);

		bool flag = false;

		for (auto i : ans){
			if (i == k){
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

		ans.clear();
		basis.clear();
	}

	return 0;
}