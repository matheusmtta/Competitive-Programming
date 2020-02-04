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
	while (t--){
		int64 ans = 0;
		vector <int32> arr;
		while (true){
			int l; cin >> l;
			if (l == 0) {
				break;
			}

			arr.push_back(l);
		}
		sort(arr.begin(), arr.end(), compare);

		for (int i = 1; i <= arr.size(); i++){
			int idx = i - 1;
			ans += 2*pow(arr[idx], i);
		}

		if (ans <= 5*1e6) cout << ans << endl;
		else cout << "Too expensive" << endl;
	}
}