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
	int t; cin >> t;

	while (t--){
		int S, A, F;
		cin >> S >> A >> F;
		vector <int> av, st;
		for (int i = 0; i < F; i++){
			int s, a; cin >> s >> a;
			av.push_back(a);
			st.push_back(s);
		}

		sort(av.begin(), av.end());
		sort(st.begin(), st.end());

		int p;

		if (F%2 == 0)
			p = (F/2)-1;
		else p = (F/2);


		cout << "(Street: " << st[p] << ", Avenue: " << av[p] << ")" << endl;
	}
	
	return 0;
}