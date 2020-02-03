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
	return abs(b) < abs(a);
}

int main(){
	
	int t; cin >> t;

	while (t--){
		int n; cin >> n;

		vector <int> floors;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			floors.push_back(x);
		}

		sort(floors.begin(), floors.end(), compare);

		int ans = 0;

		int lst = -1;

		for (int i = 0; i < n; i++){
			if (floors[i] > 0 && lst == -1) {ans++; lst = 1;}
			if (floors[i] < 0 && lst == 1) {ans++; lst = -1;}
		}

		int ans2 = 0;

		lst = 1;

		for (int i = 0; i < n; i++){
			if (floors[i] > 0 && lst == -1) {ans2++; lst = 1;}
			if (floors[i] < 0 && lst == 1) {ans2++; lst = -1;}
		}

		cout << max(ans, ans2) << endl;
	}
	
	return 0;
}