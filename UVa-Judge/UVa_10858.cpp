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

vector <vector <int>> ans;

void f(int t, int p, vector <int> &factors, int n){
	if (t == n) {
		ans.push_back(factors);
		return;
	}

	int lim = n/t;

	for (int i = p; i <= lim; i++){
		if (lim%i == 0){
			factors.push_back(i);
			f(t*i, i, factors, n);
			factors.pop_back();
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	while (true){
		cin >> q;
		if (q == 0) return 0;

		vector <int> factors;
		for (int i = 2; i*i <= q; i++){
			if (q%i == 0){
				int p = i;
				factors.push_back(i);
				f(p, p, factors, q);
				factors.pop_back();
			}
		}

		cout << ans.size() << endl;

		for (int i = 0; i < ans.size(); i++){
			for (int j = 0; j < ans[i].size(); j++){
				cout << ans[i][j]; j != ans[i].size() - 1 ? cout << " " : cout << "";
			}
			cout << endl;
		}

		ans.clear();	
	}

	return 0;
}