#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define endl "\n"
#define f first
#define s second
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int ll;
typedef unsigned long long int  ull;

int lower_bound(int x, int n, auto &dist){
	int l = 0, r = n, idx = 0;

	while (l <= r){
		int mid = (l+r)/2;
		if (dist[mid] < x)
			l = mid + 1;
		else {
			idx = mid;
			r = mid - 1;
		}
	}

	return idx;
}

int LIS(vector <int> &arr){
	int n = (int)arr.size();
	vector <int> dist(n+1, INF);
	dist[0] = -INF;

	for (int i = 0; i < n; i++){
		int pos = lower_bound(arr[i], n, dist);
		if (dist[pos-1] < arr[i] && arr[i] < dist[pos]){
			dist[pos] = arr[i];
		}
	}

	int ans = n;

	while (dist[ans] == INF)
		ans--;

	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k = 1; cin >> t;
	while (t--){	
		unordered_map <int, int> mp;
		vector <int> arr;

		int n, p, q; cin >> n >> p >> q; p++; q++;
		vector <int> prince(p);
		vector <int> princess(q);

		for (int &x : prince)
			cin >> x;
		for (int &x : princess)
			cin >> x;

		if (p > q){
			swap(p, q);
			swap(prince, princess);
		}

		for (int i = 0; i < p; i++)
			mp[prince[i]] = i;

		for (int i = 0; i < q; i++){
			if (mp.count(princess[i]))
				arr.push_back(mp[princess[i]]);
		}

		cout << "Case " << k++ << ": " << LIS(arr) << endl;
	}	

	return 0;
}