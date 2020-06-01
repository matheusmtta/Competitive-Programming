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

int main(){	
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int C, S, q = 1;

	while (cin >> C >> S){
		vector <int> arr;
		double me = 0;

		for (int i = 0; i < S; i++){
			int x; cin >> x;
			me += x;
			arr.push_back(x);
		}

		me /= C;

		//cout << me << endl;

		int aux1 = S - C;
		int aux2 = S - (aux1*2);

		while (aux2--) arr.push_back(0);
	
		sort(arr.begin(), arr.end());

		vector <int> ans[C];

		for (int i = 0; i < C; i++){
			ans[i].push_back(arr[i]);
			ans[i].push_back(arr[arr.size()-i-1]); 
		}

		double rsp = 0, diff = 0;

		cout << "Set #" << q << endl;
		for (int i = 0; i < C; i++){
			cout << " " << i << ":";
			diff = 0;
			for (int j = 0; j < ans[i].size(); j++){
				if (ans[i][j]) cout << " " << ans[i][j];
				diff += ans[i][j];
			}
			rsp += abs(diff - me);
			cout << endl;
		}
		printf("IMBALANCE = %.5lf\n", rsp);
		cout << endl;

		q++;
	}

	return 0;
}