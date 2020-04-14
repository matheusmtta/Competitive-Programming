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

	vector <char> alp;

	for (char a = 'a'; a <= 'z'; a++)
		alp.push_back(a);

	while (t--){
		int n, a, b;
		cin >> n >> a >> b;

		int i = 0;

		while (i < n){
			cout << alp[(i%b)%a];
			i++;
		}
		cout << endl;
	}

	return 0;
}