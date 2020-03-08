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

bool compare(const pair <int, int> &a, const pair <int, int> &b){
	if (a.second != b.second) return a.second < b.second;
	else return a.first > b.first;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a;
	int q = 1;

	while (cin >> a){
		if (q != 1) cout << endl;
		q++;
		map <int, int> mp;
		for (int i = 0; i < a.length(); i++){
			mp[(int)a[i]] += 1;
		}

		vector <pair <int, int> > vec;

		for (auto i : mp){
			vec.push_back(MP(i.first, i.second));
		}

		sort(vec.begin(), vec.end(), compare);

		for (int i = 0; i < vec.size(); i++)
			cout << vec[i].first << " " << vec[i].second << endl;
	}

	return 0;
}