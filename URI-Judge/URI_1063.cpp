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

	int n;
	while (true){
		cin >> n; if (n == 0) return 0;
		vector <char> in(n);
		vector <char> out(n);

		for (int i = 0; i < n; i++){
			cin >> in[i];
		}

		for (int i = 0; i < n; i++){
			cin >> out[i];
		}

		string ans;

		int i = 0, j = 0;

		stack <char> tt;

		bool rsp = true;

		while (true){
			if (!tt.empty() && j < n && tt.top() == out[j]){
				tt.pop();
				j++;
				ans += "R";
			}
			else if (i < n){
				tt.push(in[i]);
				ans += "I";
				i++;
			}
			else break;
		}

		if (tt.empty()) cout << ans << endl;
		else cout << ans << " " << "Impossible" << endl;
	}

	return 0;
}