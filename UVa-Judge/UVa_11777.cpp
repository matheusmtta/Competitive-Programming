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
	int t, q = 1;
	cin >> t;

	while (t--){

		float a, b, c, d, sum;
		vector <float> e;

		cin >> a >> b >> c >> d;

		for (int i = 0; i < 3; i++){
			int x; cin >> x;
			e.push_back(x);
		}

		sort(e.begin(), e.end());

		sum = a+b+c+d+((e[1]+e[2])/2);

		cout << "Case " << q << ": ";
		if (sum >= 90) cout << "A" << endl;
		else if (sum < 90 && sum >= 80) cout << "B" << endl;
		else if (sum < 80 && sum >= 70) cout << "C" << endl;
		else if (sum < 70 && sum >= 60) cout << "D" << endl;
		else cout << "F" << endl;

		q++;
	}
}