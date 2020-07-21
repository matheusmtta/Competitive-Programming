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
		string a, b; 
		string str; 
		cin >> str; 
		a += str;
		cin >> str;
		b += str;
		a += '0'; b += '0';
		int count = 0;
		vector <int> ans1, ans2;
		for (int i = 1; i < n+1; i++)
			if (a[i-1] != a[i]) 
				ans1.pb(i);
		for (int i = 1; i < n+1; i++)
			if (b[i-1] != b[i]) 
				ans2.pb(i);
		cout << ans1.size() + ans2.size();
		for (auto k : ans1)
			cout << " " << k;
		reverse(ans2.begin(), ans2.end());
		for (auto k : ans2)
			cout << " " << k;
		cout << endl;
	}

	return 0;
}