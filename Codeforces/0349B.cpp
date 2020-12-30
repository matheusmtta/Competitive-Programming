#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;
 
bool comp(const pair<int, int> &a, const pair <int, int> &b){
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	
	vector <pair<int, int>> arr;
	vector <int> compress(10);
	
	for (int i = 1; i <= 9; i++){
		int x; cin >> x;
		arr.push_back({x, i}); 
		compress[i] = x;
	}

	sort(arr.begin(), arr.end(), comp);

	if (arr[0].first > n){
		cout << -1 << endl;
		exit(0);
	}

	string ans;
	int idx = 0;

	while (n - arr[idx].first >= 0){
		n -= arr[idx].first;
		ans += to_string(arr[idx].second);
	}

	for (int i = 0; i < ans.size(); i++){
		int curr = ans[i] - '0';
		for (int j = 9; j >= 1 && j > curr; j--){
			int diff = abs(compress[curr] - compress[j]);
			if (n - diff >= 0){
				n -= diff;
				ans[i] = '0' + j;
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}