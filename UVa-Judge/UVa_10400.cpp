#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n, p;
map <pair<int, int>, int> mp;
vector <int> arr;
string ans;

bool bounded(int var){ if (var >  32000 || var < -32000) return false; return true; }

int dp(int idx, int tot){
	if (idx == n){
		if (tot == p) return 1;
		return 0;
	}

	if (mp.find({idx, tot}) != mp.end())
		return mp[{idx, tot}];

	int &curr = mp[{idx, tot}] = 0;

	if (bounded(tot+arr[idx])){
		curr = dp(idx+1, tot+arr[idx]);
		if (curr){
			ans[idx] = '+';
			return curr;
		}
	}
	if (bounded(tot-arr[idx])){
		curr = dp(idx+1, tot-arr[idx]);
		if (curr){
			ans[idx] = '-';
			return curr;
		}
	}
	if (bounded(tot*arr[idx])){
		curr = dp(idx+1, tot*arr[idx]);
		if (curr){
			ans[idx] = '*';
			return curr;
		}
	}
	if (tot%arr[idx] == 0 && bounded(tot/arr[idx])){
		curr = dp(idx+1, tot/arr[idx]);
		if (curr){
			ans[idx] = '/';
			return curr;
		}
	}

	return curr;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		cin >> n;
		arr.resize(n);

		for (int &x : arr)
			cin >> x;
		cin >> p;

		for (int i = 0; i < n; i++) ans += "=";

		int rsp = dp(0, 0);
		
		if (rsp){
			cout << arr[0];
			for (int i = 1; i < n; i++){
				cout << ans[i] << arr[i];
			}
			cout << "=" << p << endl;
		}
		else
			cout << "NO EXPRESSION" << endl;

		mp.clear();
	}	

	return 0;
}