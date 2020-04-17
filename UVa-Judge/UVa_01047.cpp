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

vector <pair<vector<int>, int>> choices;
vector <int> basis;
map <int, int> mp;
int n, k;

void build(vector <int> perm, int idx){
	if (perm.size() == k){
		int sum = 0;
		for (auto l : perm)
			sum += mp[l];
		choices.push_back(MP(perm, sum));
	}
	if (perm.size() > k) 
		return;

	for (int i = idx; i < basis.size(); i++){
		perm.push_back(basis[i]);
		build(perm, i+1);
		perm.pop_back();
	}

	return;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (true){
		cin >> n >> k;
		if (n == 0 && k == 0) exit(0);

		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			mp[i] = x;
			basis.push_back(i);
		}

		vector <int> perm;

		build(perm, 0);

		int num; cin >> num;

		vector <pair<vector<int>, int>> inter;

		while (num--){
			int p; cin >> p;
			vector <int> tmp;
			for (int i = 0; i < p; i++){
				int x; cin >> x;
				tmp.push_back(x);
			}

			int h; cin >> h;

			inter.push_back(MP(tmp, h));
		}

		for (int i = 0; i < choices.size(); i++){
			for (int j = 0; j < inter.size(); j++){
				int count = 0;
				for (int k = 0; k < inter[j].first.size(); k++){
					if (find(choices[i].first.begin(), choices[i].first.end(), inter[j].first[k]) != choices[i].first.end())
						count++;
				}
				if (count > 1){ 
					choices[i].second -= inter[j].second*(count-1);
				}
			}
		}

		pair <vector<int>, int> mx;

		mx.second = -1;

		for (auto i : choices){
			if (mx.second < i.second)
				mx = i;
		}

		cout << "Case Number  " << q << endl;
		cout << "Number of Customers: " << mx.second << endl;
		cout << "Locations recommended:";
		for (auto i : mx.first)
			cout << " " << i;
		cout << endl;

		mp.clear();
		basis.clear();
		choices.clear();
		q++;
		cout << endl;
	}

	return 0;
}