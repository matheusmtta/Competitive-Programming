#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define end "\n"
#define first f
#define second s
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll

typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector <int> div;

	for (int i = 4; i <= 777; i++){
		int curr = i;
		bool flag = true;
		while (curr > 0){
			int d = curr%10; curr/=10;
			if (d != 7 && d != 4)
				flag = false;
		}
		if (flag)
			div.push_back(i);
	}

	bool flag = false;

	for (auto x : div)
		if (n%x == 0)
			flag = true;

	flag ? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}
