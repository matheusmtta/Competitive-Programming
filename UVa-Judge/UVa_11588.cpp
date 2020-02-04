#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)1e9
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

bool compare(const int &a, const int &b){
	return b < a;
}

int main(){
	int t;
	cin >> t;
	int q =1;

	while (t--){
		int n, m, mx, mn;
		cin >> n >> m >> mx >> mn;

		vector <int> arr(26, 0);

		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char x; cin >> x;
				arr[x - 'A']++;
			}
		}

		vector <int> ans;

		for (int i = 0; i < 26; i++){
			if (arr[i] != 0)
				ans.push_back(arr[i]);
		}

		sort(ans.begin(), ans.end(), compare);

		int idx = 1;

		int tmp = ans[0];


		while (ans[idx-1] == ans[idx]) {tmp += ans[idx]; idx++;}


		int rsp = tmp*mx;
		rsp += ((n*m)-tmp)*mn;

		cout << "Case " << q << ": " << rsp << endl; 
	}
}