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

	int t, flag = 0;
	while (true){
		cin >> t;
		if (t == 0) return 0;
		while (true){
			vector <int> trains;

			for (int i = 0; i < t; i++)
				trains.push_back(i+1);

			bool end = false;

			vector <int> out(t);

			for (int i = 0; i < t; i++){
				cin >> out[i];
				if (out[i] == 0) {
					end = true;
					cout << endl;
					break;
				}
			}

			if (end) break;

			stack <int> tt;

			bool ans = true;

			int in = 0, ot = 0, aux;

			while (true){
				if (in == t) break;
				if (!tt.empty() && tt.top() == out[ot]){
					tt.pop();
					ot++;
				}
				else if (trains[in] != out[ot]){
					if (tt.empty() || tt.top() != trains[in]) {
						aux = trains[in];
						tt.push(aux);
						in++;
					}
					else if (tt.top() == out[ot]){
						tt.pop();
						ot++;
					}
				}
				else if (trains[in] == out[ot]){
					ot++;
					in++;
				}
			}

			while (!tt.empty()){
				int s = tt.top();
				tt.pop();
				if (s != out[ot]) ans = false;
				ot++;
			}

			if (ans) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}

	return 0;
}