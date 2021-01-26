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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m; 
		vector <int64> arr, a, b;

		int64 sum = 0;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			sum += x;
			arr.push_back(x);
		}

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (x == 2)
				b.push_back(arr[i]);
			else
				a.push_back(arr[i]);
		}

		if (sum < m){
			cout << -1 << endl;
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 1; i < a.size(); i++)
			a[i] += a[i-1];

		for (int i = 1; i < b.size(); i++)
			b[i] += b[i-1];

		int ans = INF;

		int l = 0, r = b.size()-1;
		while (l <= r && (int)b.size()){
			int mid = (l+r) >> 1;
			if (b[mid] >= m){
				r = mid - 1;
				ans = min(ans, 2*(mid+1));
			}
			else 
				l = mid + 1;
		}

		l = 0, r = a.size()-1;
		while (l <= r && (int)a.size()){
			int mid = (l+r) >> 1;
			if (a[mid] >= m){
				r = mid - 1;
				ans = min(ans, mid+1);
			}
			else
				l = mid + 1;
		}

		for (int i = 0; i < a.size() && (int)a.size() && (int)b.size(); i++){
			int del = a[i];
			
			if (del >= m)
				ans = min(ans, i+1);

			l = 0, r = b.size()-1;
			while (l <= r){
				int mid = (l+r) >> 1;
				if (del + b[mid] >= m){
					ans = min(ans, (i+1) + 2*(mid+1));		
					r = mid - 1;
				}
				else
					l = mid + 1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}