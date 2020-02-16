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

map <string, string> genes;
map <string, vector <string>> p;

void solve(string child, string p1, string p2){

	if (genes.find(p1) == genes.end())
		solve(p1, p[p1][0], p[p1][1]);
	if (genes.find(p2) == genes.end())
		solve(p2, p[p2][0], p[p2][1]);

	bool flag = false;

	if (genes[p1] != "non-existent" && genes[p2] != "non-existent")
		flag = true;
	else if (genes[p1] == "dominant" || genes[p2] == "dominant")
		flag = true;

	if (flag){
		if (genes[p1] == "dominant" && genes[p2] == "dominant")
			genes[child] = "dominant";
		else if (genes[p1] == "recessive" && genes[p2] == "dominant")
			genes[child] = "dominant";
		else if (genes[p1] == "dominant" && genes[p2] == "recessive")
			genes[child] = "dominant";
		else genes[child] = "recessive";
	}
	else
		genes[child] = "non-existent";
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	while (n--){
		string a, b;
		cin >> a >> b;

		if (b == "dominant" || b == "recessive" || b == "non-existent"){
			genes[a] = b;
		}
		else {
			p[b].push_back(a);
		}
	}

	for (auto i : p)
	 	solve(i.first, i.second[0], i.second[1]);

	for (auto i: genes)
	 	cout << i.first << " " << i.second << endl;

	return 0;
}