#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector <pair<int,int>> dolls;
		for (int i = 0; i < n; i++){
			int w, h; cin >> w >> h;
			dolls.push_back({w, h});
		}
		sort(dolls.begin(), dolls.end(), comp);

		deque <pair<int, int>> ans;
		ans.push_back(dolls[0]);

		for (int i = 1; i < n; i++){
			int l = 0, r = ans.size() - 1;
			int idx = 0;
			while (l <= r){
				int mid = (l+r)/2;
				if (ans[mid].second < dolls[i].second){
					l = mid + 1;
					idx = mid;
				}
				else 
					r = mid - 1;
			}
			if (ans[idx].first < dolls[i].first && 
				ans[idx].second < dolls[i].second){
				ans[idx].first = dolls[i].first;
				ans[idx].second = dolls[i].second;
			}
			else {
				ans.push_front(dolls[i]);
			}
		}

		cout << ans.size() << endl; 
	}	

	return 0;
}