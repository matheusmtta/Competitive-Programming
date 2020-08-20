#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int64 n;
map <pair<int, int64>, int64> memo;
vector <int64> arr;

int64 dp(int64 idx, int64 prod, bool pick){
	if (idx == n) return prod;
	if (memo.find({idx, prod}) != memo.end())
		return memo[{idx, prod}];
	if (!pick)
		prod = 1;
	return memo[{idx, prod}] = max(dp(idx+1, -LINF, false), dp(idx+1, prod*arr[idx], true));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64 a;

	while (1){
		while (cin >> a){
			if (a == -999999) break;
			arr.push_back(a);
		}

		if (arr.size() == 0) return 0;
	
		n = arr.size();

		cout << dp(0, 0, false) << endl;
		
		memo.clear();
		arr.clear();
	}


	return 0;
}