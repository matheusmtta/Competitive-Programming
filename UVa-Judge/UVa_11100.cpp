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

bool comp(const int &a, const int &b){
	return a > b;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	bool flag = false;

	while (cin >> n){
		if (n == 0) return 0;
		vector <int> bags;

		if (flag) cout << endl;

		flag = true;

		for (int i = 0; i < n; i++){
			int x; cin >> x;
			bags.push_back(x);
		}

		sort(bags.begin(), bags.end(), comp);

		vector <bool> aux(n, false);

		vector <vector<int>> ans;

		for (int i = 0; i < n; i++){
			vector <int> tmp;
			queue <int> q;
			if (!aux[i]){
				q.push(bags[i]);
				aux[i] = true;
				tmp.push_back(bags[i]);
			}
			while (!q.empty()){
				int curr = q.front();
				q.pop();
				for (int j = i+1; j < n; j++){
					if (bags[j] < curr && !aux[j]){
						q.push(bags[j]);
						aux[j] = true;
						tmp.push_back(bags[j]);
						curr -= bags[j];
					}
				}
			}
			if (tmp.size()) ans.push_back(tmp);
		}
		cout << ans.size() << endl;
		for (auto k : ans){
			for (int i = 0; i < k.size(); i++){
				cout << k[i];
				if (i != k.size()-1) cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}