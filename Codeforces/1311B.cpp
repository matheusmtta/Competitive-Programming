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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		vector <int> arr;
		vector <int> p(n, 0);

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			arr.push_back(x);
		}

		for (int i = 0; i < m; i++){
			int x; cin >> x; x--;
			p[x] = 1;
		}

		vector <int> aux = arr;

		sort(aux.begin(), aux.end());

		bool change = true;

		while (true){
			if (!change) break;
			change = false;
			for (int i = 0; i < n; i++){
				if (p[i] == 1){
					if ((i != n-1) && arr[i] > arr[i+1]){
						swap(arr[i], arr[i+1]);
						change = true;
					}
				}
			}
		}

		arr == aux ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}