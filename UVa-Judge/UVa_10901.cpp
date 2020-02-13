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
		int n, m, tm;
		cin >> n >> tm >> m;

		queue <pair <int,int>> left, right;
		vector <int> ans(m);

		string str;
		int x;

		for (int i = 0; i < m; i++){
			cin >> x >> str;
			if (str == "left")
				left.push(MP(i, x));
			else
				right.push(MP(i,x));
		}

		int curr = 0;

		bool flag = false;
		//false -> left
		//true -> right

		while (!(left.empty() && right.empty())){
			int aux = INF; 

			if (!left.empty())
				aux = left.front().second;
			if (!right.empty())
				aux = min(aux, right.front().second);

			curr = max(aux, curr);

			int count = 0;

			if (!flag){
				while (!left.empty() &&
					   left.front().second <= curr &&
					   count < n){
					ans[left.front().first] = curr + tm;
					count++;
					left.pop();
				}
				curr += tm;
				flag = true;
			}
			else{
				while (!right.empty() &&
					   right.front().second <= curr &&
					   count < n){
					ans[right.front().first] = curr + tm;
					count++;
					right.pop();
				}
				curr += tm;
				flag = false;
			}
		}

		for (int i = 0; i < ans.size(); i++){
			cout << ans[i] << endl;
		}

		if (t != 0) cout << endl;
	}

	return 0;
}