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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector <int> c; 

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		c.push_back(x);
	}

	int k; cin >> k;

	pair <int, int> ans;

	for (int i = 0; i < k; i++){
		ans.first = ans.second = -1;

		int l, r; l = 0, r = n-1;
		
		int s; cin >> s;

		while (l <= r){
			int mid = (l+r)/2;
			if (c[mid] >= s)
				r = mid-1;
			else{
				l = mid+1;
				ans.first = mid;
			}
		}

		l = 0, r = n-1;

		while (l <= r){
			int mid = (l+r)/2;
			if (c[mid] <= s)
				l = mid+1;
			else {
				r = mid-1;
				ans.second = mid;
			}
		}

		if (ans.first == -1) cout << "X ";
		else cout << c[ans.first] << " ";
		if (ans.second == -1) cout << "X" << endl;
		else cout << c[ans.second] << endl;
	}

	return 0;
}