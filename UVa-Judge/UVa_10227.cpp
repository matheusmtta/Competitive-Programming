 
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

	int t; cin >> t;
	while (t--){
		int P, T;
        cin >> P >> T;

        string str;

        set <int> tree[P+1];

        cin.ignore();

		int i, j;

		while(getline(cin, str)) {
			if(str.length() == 0)
				break;
			stringstream ss;
			ss << str;
			vector <int> aux;

			while (!ss.eof()){
				int tmp;
				ss >> tmp;
				aux.push_back(tmp);
			}

			i = aux[0];
			j = aux[1];

			tree[i].insert(j);
		}

		set <set <int>> op;

		for (int k = 1; k <= P; k++){
			op.insert(tree[k]);
		}

		cout << op.size() << endl;

		if (t) cout << endl;
	}

	return 0;
}