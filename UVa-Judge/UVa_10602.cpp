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

int gss(string a, string b){
	int s = a.size(), t  = b.size(), ans = 0;
	for (int i = 0; i < min(s, t); i++){
		if (a[i] != b[i])
			break;
		ans++;
	}
	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		vector <string> arr;
		
		for (int i = 0; i < n; i++){
			string str; cin >> str;
			arr.push_back(str);
		}

		bitset <10000> used;

		vector <string> ans;
		int j = 1;

		ans.push_back(arr[0]);
		used[0] = 1;
		int count = arr[0].size();

		while (j < n){
			string curr = ans[ans.size()-1];
			int idx = -1, mx = -1;
			for (int i = 0; i < n; i++){
				if (!used[i]){	
					int tmp = gss(curr, arr[i]);
					if (tmp > mx){
						idx = i;
						mx = tmp;
					}
				}
			}
			used[idx] = 1;
			count += arr[idx].size() - mx;
			ans.push_back(arr[idx]);
			j++;
		}

		cout << count << endl;
		for (auto k : ans)
			cout << k << endl;
	}

	return 0;
}