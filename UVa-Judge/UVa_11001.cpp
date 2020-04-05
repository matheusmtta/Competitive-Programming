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

bool compare(const pair<int, double> &a,
			 const pair<int, double> &b){
	return a.second > b.second;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true){
		int V, Vo;
		cin >> V >> Vo;

		if (V == 0 && Vo == 0) exit(0);

		int aux = 1;

		double div = V/aux;

		vector <pair<int, double>> ans;

		while (div > Vo){
			double lgt = 0.3*(sqrt(div-Vo));
			ans.push_back(MP(aux, aux*lgt));
			//cout << aux << " " << aux*lgt << endl;
			aux++;
			div = V/(1.0*aux);
		}

		sort(ans.begin(), ans.end(), compare);

		// for (int i = 0; i < ans.size(); i++)
		// 	cout << ans[i].first << " " << ans[i].second << endl;

		if (ans.size() == 0 || (ans.size() > 1 && abs(ans[0].second-ans[1].second) < 1e-6))
			cout << 0 << endl;
		else cout << ans[0].first << endl;
	}

	return 0;
}