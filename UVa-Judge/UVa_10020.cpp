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

bool compare(const pair<int, int> &a, const pair <int, int> &b){
	if (a.first == b.first){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		vector <pair<int, int>> arr;

		int a, b;

		int M; cin >> M;

		while (cin >> a >> b){
			if (a == 0 && b == 0) break;
			if (a < 0 && b < 0) continue;
			
			arr.push_back({a, b});
		}

		sort(arr.begin(), arr.end(), compare);

		int cov = 0;
		int idx = 0;
		bool ans = true;
		int n = arr.size();

		vector <pair<int, int>> chosen;

		while (idx < n && cov <= M){
			pair <int, int> tmp;
			if (cov >= arr[idx].first && cov <= arr[idx].second){

				tmp = arr[idx];
				int j = idx+1;
				while (j < n){
					if (cov < arr[j].first) break;
					if (cov >= arr[j].first && arr[j].second >= tmp.second){
						tmp = arr[j];
					}
					j++;
				}
				chosen.push_back(tmp);
				cov = tmp.second;
				if (cov >= M) break;	
			}
			idx++;
		}

		bitset <1000100> aux;

		for (auto k : chosen){
			for (int i = k.first >= 0 ? k.first : 0; i <= k.second; i++){
				aux[i] = 1;
			}
		}

		for (int k = 0; k <= M; k++){
			if (!aux[k]) ans = false;
		}

		if (ans){
			cout << chosen.size() << endl;
			for (auto k : chosen){
				cout << k.first << " " << k.second << endl;
			}
		}
		else 
			cout << 0 << endl;
		if (t) cout << endl;
	}

	return 0;
}