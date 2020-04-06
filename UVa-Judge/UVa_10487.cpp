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
	int c = 1;

	while (cin >> n){
		if (n == 0) break;
		vector <int> a;
		vector <int> sum;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			for (int j = 0; j < a.size(); j++){
				sum.push_back(a[j]+x);
			}
			a.push_back(x);
		}

		int q; cin >> q;

		vector <pair<int, int>> rsp;

		for (int i = 0; i < q; i++){
			int s; cin >> s;
			int choice = INF;
			int tmp = INF;
			for (int j = 0; j < sum.size(); j++){
				if (abs(sum[j]-s) < tmp){
					tmp = abs(sum[j]-s);
					choice = sum[j];
				}
			}
			rsp.push_back(MP(s, choice));
		}

		cout << "Case " << c << ":" << endl;

		for (int i = 0; i < rsp.size(); i++){
			cout << "Closest sum to " << rsp[i].first << " is " << rsp[i].second << '.' << endl;
		}
		c++;
	}

	return 0;
}