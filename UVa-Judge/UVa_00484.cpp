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

	int x; 

	map <int, int> mp;
	vector <int> arr;

	while (cin >> x){
		if (mp[x] == 0) arr.push_back(x);
		mp[x]++;
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " " << mp[arr[i]] << endl;

	return 0;
}