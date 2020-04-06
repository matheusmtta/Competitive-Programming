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

int allow(int a, int b){
	int sz1 = log10(a)+1;
	int sz2 = log10(b)+1;
	if (sz1 + sz2 < 9 || sz1 + sz2 > 10) return false;

	bitset <10> digits;

	int r = a%10;

	while (a != 0){
		if (digits[r]) return false;
		digits[r] = true;
		a /= 10;
		r = a%10;
	}

	r = b%10;

	while (b != 0){
		if (digits[r]) return false;
		digits[r] = true;
		b /= 10;
		r = b%10;
	}

	if ((sz1 == 4 || sz2 == 4) &&
		 digits[0] == false &&
		 digits.count() == 9)
		return true;
	if ((sz1 == 5 && sz2 == 5) &&
		 digits.count() == 10)
		return true;
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool flag = false;

	while (true){
		int n; cin >> n;
		if (n == 0) exit(0);

		if (flag) cout << endl;

		flag = true;

		vector <pair<int, int>> ans;

		int i = 1234;

		while ((int)log10(i*n) <= 5){
			if (allow(i*n, i))
				ans.push_back(MP(i*n, i));
			i++;
		}

		if (!ans.size()) cout << "There are no solutions for " << n << "." << endl;
		else{
			for (int i = 0; i < ans.size(); i++){
				if ((int)log10(ans[i].first)+1 == 4) cout << "0";
				cout << ans[i].first << " / ";
				if ((int)log10(ans[i].second)+1 == 4) cout << "0";
				cout << ans[i].second << " = " << n << endl;
			}
		}
	}

	return 0;
}