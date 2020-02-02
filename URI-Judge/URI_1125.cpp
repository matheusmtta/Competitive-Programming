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
	while (true){
		int G, P; cin >> G >> P;
		if (G == 0 && P == 0) return 0;
		vector <pair <int, int > > pilots(P);
		vector <int> gp[G];

		for (int i = 0; i < pilots.size(); i++){
			pilots[i].first = 0;
			int aux = i + 1;
			pilots[i].second = aux;
		}


		for (int i = 0; i < G; i++){
			for (int j = 0; j < P; j++){
				int x; cin >> x;
				gp[i].push_back(x);
			}
		}

		int S; cin >> S;

		while (S--){
			int K; cin >> K;
			vector <int> points(K+1);

			for (int i = 1; i <= K; i++){
				int x; cin >> x;
				points[i] = x;
			}
			
			for (int i = 0; i < G; i++){
				for (int j = 0; j < P; j++){
					int pos = gp[i][j];
					if (pos <= K){
						pilots[j].first += points[pos]; 
					}
				}
			}

			sort(pilots.begin(), pilots.end());
			reverse(pilots.begin(), pilots.end());

			int idx = 0;

			vector <int> ans;

			if (P > 1 && pilots[idx].first == pilots[idx+1].first){
				idx = 1;
				ans.push_back(pilots[0].second);
				while (idx < P && pilots[idx].first == pilots[idx - 1].first){
					ans.push_back(pilots[idx].second);
					idx++;
				}

				sort(ans.begin(), ans.end());

				for (int i = 0; i < ans.size(); i++){
					cout << ans[i];
					if (i != ans.size() - 1) cout << " ";
				}
				cout << endl;
			}
			else cout << pilots[idx].second << endl;

			for (int i = 0; i < pilots.size(); i++){
				pilots[i].first = 0;
				pilots[i].second = i+1;
			}
		}
	}

	return 0;
}