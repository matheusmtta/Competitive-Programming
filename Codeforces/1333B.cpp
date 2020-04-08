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

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		vector <int64> a;
		vector <int64> b;
		vector <int> aux;
		
		int fn = INF, fp = INF; 

		bool ans = true;

		bool flag1 = false, flag2 = false;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			if (x == 1 && !flag1) {fp = i; flag1 = true;}
			if (x == -1 && !flag2) {fn = i; flag2 = true;}
			a.push_back(x);
		}

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			aux.push_back(a[i] - x);
		}

 
		for (int i = n-1; i >= 0; i--){
			if (aux[i] != 0){
				if (aux[i] > 0 && (fn == INF || fn >= i)) ans = false;
				if (aux[i] < 0 && (fp == INF || fp >= i)) ans = false; 
			}
		}

		ans ? cout << "YES" << endl : cout << "NO" << endl;
	}

	return 0;
}