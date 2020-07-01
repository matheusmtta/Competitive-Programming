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

vector <int> a, b;

bool comp1 (const int &i, const int &j){
	return a[i] < a[j];
}

bool comp2 (const int &i, const int &j){
	return b[i] > b[j];
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (cin >> n){
		vector <pair<int, int>> arr;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			b.push_back(x);
		}

		vector <int> idx(n, -1);
		vector <int> aux1, aux2;

		int r = n-1, l = 0;

		for (int i = 0; i < n; i++){
			if (a[i] < b[i]) {
				aux1.push_back(i);
			}
			else {
				aux2.push_back(i);
			}
		}

		sort(aux1.begin(), aux1.end(), comp1);
		sort(aux2.begin(), aux2.end(), comp2);

		for (int i = 0; i < n; i++){
			if (i >= aux1.size())
				idx[i] = aux2[i-aux1.size()];
			else
				idx[i] = aux1[i];
		}

		int ans, lst;
		ans = lst = 0;

		for (int i = 0; i < n; i++){
			lst += a[idx[i]];
			ans = max(ans, lst) + b[idx[i]];
		}

		cout << ans << endl;

		a.clear();
		b.clear();
	}

	return 0;
}