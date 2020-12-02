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

	string str; cin >> str;
	char curr = str[0];
	int count = 1;

	bool flag = false;

	for (int i = 1; i < str.size(); i++){
		if (str[i] == curr)
			count++;
		else count = 1;
		if (count >= 7) flag = true;
		curr = str[i];
	}

	flag ? cout << "YES" << endl : cout << "NO" << endl;

	return 0;
}
