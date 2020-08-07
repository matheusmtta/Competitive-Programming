#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

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
		vector <int> arr;
		vector <int> d;
		bitset <100> aux;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
			if (!aux[x])
				d.push_back(x);
			aux[x] = 1;
		}
		sort(arr.begin(), arr.end());
		set <int> diff;
		for (int i = 0; i < d.size(); i++)
			for (int j = 0; j < d.size(); j++)
				diff.insert(d[i]+d[j]);
		int mx = -1;
		int ans = 0;
		for (auto i : diff){
			int l = 0, r = arr.size()-1;
			int curr = 0;
			while (l < r){
				if (arr[l]+arr[r] == i){
					curr++;
					l++;
					r--;
					continue;
				}
				if (arr[l]+arr[r] > i)
					r--;
				else if (arr[l]+arr[r] < i)
					l++;
			}
			if (curr > ans){
				ans = curr;
			}
		}

		cout << ans << endl;
	}

	return 0;
}