#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

//LCS O(nm)

int n, m; //string sizes
int memo[100][100];
string a, b;
vector <char> r;

int LCS(int i, int j){
	if (i == a.size() || j == b.size()) return 0;
	int &qry = memo[i][j];

	if (qry != -1) return qry;

	qry = 0;

	if (a[i] == b[j]) qry = max(qry, 1 + LCS(i+1, j+1));

	return qry = max({qry, LCS(i+1, j), LCS(i, j+1)});
}

void recover(int i, int j){
	if (i == a.size() || j == b.size()) return;

	int q1 = LCS(i+1, j);
	int q2 = LCS(i, j+1);
	int q3 = (a[i] == b[j] ? 1 + LCS(i+1, j+1) : -INF);

	if (q3 >= q1 && q3 >= q2){
		r.push_back(a[i]);
		recover(i+1, j+1);
	}
	else if (q1 >= q2)
		recover(i+1, j);
	else
		recover(i, j+1);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	a = "AGGTAB";
	b = "GXTXAYB";

	memset(memo, -1, sizeof(memo));

	int n = a.length();
	int m = b.length();

	string ans;

	cout << "Lenght of LCS the is " << LCS(0, 0) << endl;

	recover(0, 0);

	for (auto i : r){
		ans += i;
	}

	cout << "The LCS is ''" << ans << "''" << endl;

	return 0;
}