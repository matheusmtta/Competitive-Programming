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

int n, k;
vector <int> a;
vector <int> b;
map <vector <int>, int> mp;
bool ans = false;

void find(vector <int> tmp){
	if (tmp.size() < b.size()) return;
	if (tmp.size() == b.size() && tmp == b){
	 	ans = true;
	}

	mp[tmp] = 1;

	vector <int> aux = tmp;
	reverse(aux.begin(), aux.end());

	for (int i = 0; i <= tmp.size(); i++){
		vector <int> nx(max(i, (int)tmp.size()-i), 0);

		int idx = nx.size()-1;

		for (int j = i-1; j >= 0; j--){
			nx[idx] += aux[j];
			idx--;
		}

		idx = nx.size()-1;

		for (int j = tmp.size()-i-1; j >= 0; j--){
			nx[idx] += tmp[j];
			idx--;
		}

		if (mp[nx]) continue;
		find(nx);
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){
		a.resize(n);

		for (int i = 0; i < n; i++)
			cin >> a[i];

		cin >> k;
		b.resize(k);

		for (int i = 0; i < k; i++)
			cin >> b[i];

		vector <int> tmp = a;

		find(tmp);

		if (ans) cout << "S" << endl;
		else cout << "N" << endl;
		ans = false;
		mp.clear();
	} 

	return 0;
}