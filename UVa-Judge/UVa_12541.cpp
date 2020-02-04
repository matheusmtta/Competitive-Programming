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
	int n; cin >> n;
	vector <pair <int, string>> pes;
	for (int i = 0; i < n; i++){
		int d, m, a; string tmp;
		cin >> tmp >> d >> m >> a;
		m *= 30;
		a *= 365;
		pes.push_back(MP(d+m+a, tmp));
	}
	sort(pes.begin(), pes.end());
	cout << pes[pes.size()-1].second << endl;
	cout << pes[0].second << endl;
	return 0;
}