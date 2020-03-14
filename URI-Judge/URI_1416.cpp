#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int curr = 20;

bool ranking(pair <int, pair <int, int>> a, pair <int, pair <int, int>> b){
	int k1 = a.second.first;
	int timer1 = a.second.second;

	int k2 = b.second.first;
	int timer2 = b.second.second;

	int tot1 = (k1*curr)+timer1;
	int tot2 = (k2*curr)+timer2;

	if (a.first == b.first && tot1 == tot2) return true;
	return false;
}

bool compare(const pair <int, pair <int, int>> &a, const pair <int, pair <int, int>> &b){
	if (a.first != b.first)
		return a.first > b.first;
	else {
		int k1 = a.second.first;
		int timer1 = a.second.second;
		int k2 = b.second.first;
		int timer2 = b.second.second;

		int tot1 = (k1*curr)+timer1;
		int tot2 = (k2*curr)+timer2;

		return tot1 < tot2;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int T, P;
		vector <pair <int, pair <int, int>>> basis, scb;
		map <pair <int, pair <int, int>>, int> as;
		curr = 20;
		
		cin >> T >> P;

		if (T == 0 && P == 0) exit(0);


		for (int i = 0; i < T; i++){
			pair <int, pair <int, int>> tmp;
			for (int j = 0; j < P; j++){
				string str; int x, b; char c;
				cin >> x >> c >> str;
				if (str != "-") {
					stringstream toint(str);

					toint >> b;

					tmp.first += 1;
					tmp.second.first += x;
					tmp.second.second += b;
				}
			}
			scb.push_back(tmp);
		}

		sort(scb.begin(), scb.end(), compare);

		vector <int> ra(T, 0), rn(T, 0);

		basis = scb;

		as[basis[0]] = 1;
		for (int i = 1; i < T; i++){
			if (ranking(basis[i], basis[i-1])){
				as[basis[i]] = as[basis[i-1]];
			}
			else as[basis[i]] = as[basis[i-1]]+1;
		}

		int count = 0;
		int mn = 20, mx = -1;
		bool lim = false;
		bool flag = false;

		for (curr = 1; curr <= 10000; curr++){
			sort(scb.begin(), scb.end(), compare);

			bool eq = true;

			ra[0] = 1;
			if (as[scb[0]] != ra[0]) eq = false;
			for (int i = 1; i < T; i++){
				if (ranking(scb[i], scb[i-1])){
					ra[i] = ra[i-1];
				}
				else ra[i] = ra[i-1]+1;

				if (as[scb[i]] != ra[i]) eq = false;
			}

			if (eq) {flag = true; mn = min(curr, mn);}
			if (!eq && flag) {lim = true; mx = max(curr-1, mx); break;}
		}


		if (lim) cout << mn << " " << mx << endl;
		else cout << mn << " " << "*" << endl;
		as.clear();
		basis.clear(), scb.clear();
	}

	return 0;
}