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
	int q = 1;


	while (t--){
		int n; cin >> n;

		bool flag = false;

		cout << "Case " << q << ": ";

		map <string, int> sub;

		for (int i = 0; i < n; i++){
			int x; string str;
			cin >> str >> x;
			sub[str] = x;
		}

		int tm; cin >> tm;
		string str; cin >> str;

		if (sub.find(str) != sub.end()){
			if (sub[str] <= tm){
				cout << "Yesss" << endl;
				flag = true;
			}
			else if (sub[str] <= tm+5){
				cout << "Late" << endl;
				flag = true;
			}
		}

		if (!flag) cout << "Do your own homework!" << endl;
		q++;
	}

	return 0;
}