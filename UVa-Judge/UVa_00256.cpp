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

	int n; 

	vector <pair<int, int>> ans;

	for (int i = 1; i <= 10000; i++){
		int tmp = log10(i*i)+1;
		ans.push_back(MP(i*i, tmp));
	}

	while (cin >> n){
		for (int i = 0; i < n; i++)
			cout << 0;
		cout << endl;
		for (int i = 0; i < ans.size(); i++){
			if (ans[i].second >= n+1) break;
			int a = ans[i].first/pow(10, n/2);
			int b = ans[i].first%((int)pow(10, n/2));
			if (pow(a+b, 2) == ans[i].first)
				cout << setw(n) << setfill('0') << ans[i].first << endl;
		}
	}

	return 0;
}