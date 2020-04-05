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

	int l, h, r;
	vector <int> skl(10100, 0);
	int mx = -1;

	while (cin >> l >> h >> r){
		mx = max(mx, r);
		for (int i = l; i < r; i++)
			skl[i] = max(h, skl[i]);
	}

	int idx = 1;

	bool flag = false; 

	while (idx <= mx){
		if (skl[idx - 1] != skl[idx]){
			if (!flag){
				cout << idx << " " << skl[idx];
				flag = true;
			}
			else cout << " " << idx << " " << skl[idx];
		}
		idx++;
	}
	cout << endl;

	return 0;
}