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


	while (true){
		int n;
		cin >> n; if (n == 0) return 0;

		queue <int> cards;

		for (int i = 1; i <= n; i++)
			cards.push(i);

		vector <int> ans;

		while (cards.size() != 1){
			int x = cards.front();
			cards.pop();
			ans.push_back(x);
			x = cards.front();
			cards.pop();
			cards.push(x);
		}

		cout << "Discarded cards:";
		for (int i = 0; i < ans.size(); i++){
			if (i == 0) cout << " ";
			cout << ans[i];
			if (i != ans.size() - 1) cout << ", ";
		}
		cout << endl;
		cout << "Remaining card: " << cards.front() << endl;
	}

	return 0;
}