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

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;

	while (t--){
		int n; cin >> n;
		string c; cin >> c;

		string a, b;

		bool flag = false;

		int idx = INF;

		for (int i = 0; i < n; i++){
			if (c[i] == '1') {idx = i; break;}
		}

		for (int i = 0; i < n; i++){
			if (i > idx){
				a += '0';
				b += c[i];
			}
			else {
				if (c[i] == '1'){
					a += '1';
					b += '0';
				}
				else if (c[i] == '2'){
					a += '1';
					b += '1';
				}
				else {
					a += '0';
					b += '0';
				}
			}
		}

		cout << a << endl;
		cout << b << endl;
	}	

	return 0;
}