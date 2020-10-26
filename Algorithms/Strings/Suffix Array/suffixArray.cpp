#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long long int int64;
typedef unsigned long long int  uint64;

int n;
string str;

vector <int> pos;
vector <int> equivC;
vector <pair<char, int>> arr;
vector <pair<pair<int,int>, int>> cmp;

//Computes the suffix array of a given string
//in O(nlog^2n) :3

void init(){
	pos.resize(n); arr.resize(n); equivC.resize(n); arr.resize(n);

	for (int i = 0; i < n; i++)
		arr[i] = {str[i], i};


	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++)
		pos[i] = arr[i].second;

	equivC[pos[0]] = 0;
	for (int i = 1; i < n; i++){
		if (arr[i].first == arr[i-1].first)
			equivC[pos[i]] = equivC[pos[i-1]];
		else
			equivC[pos[i]] = equivC[pos[i-1]] + 1;
	}
}

void build(){
	cmp.resize(n);
	
	int k = 0;

	while ((1 << k) < n){
		for (int i = 0; i < n; i++)
			cmp[i] = {{equivC[i], equivC[(i + (1 << k)) % n]}, i};

		sort(cmp.begin(), cmp.end());

		for (int i = 0; i < n; i++)
			pos[i] = cmp[i].second;

		equivC[pos[0]] = 0;
		for (int i = 1; i < n; i++){
			if (cmp[i].first == cmp[i-1].first)
				equivC[pos[i]] = equivC[pos[i-1]];
			else
				equivC[pos[i]] = equivC[pos[i-1]] + 1;
		}

		k++;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	str = str + "$";

	n = str.size();

	init();
	build();

	for (int i = 0; i < n; i++)
		cout << pos[i] << " ";
	cout << endl;

	return 0;
}