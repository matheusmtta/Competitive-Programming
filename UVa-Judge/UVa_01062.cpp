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

	string str;	
	int q = 0;
	while (true){
		cin >> str;
		if (str == "end") return 0;

		vector <stack <char>> piles;
		int ans = 0;

		for (int i = 0; i < str.length(); i++){
			bool s = false;
			if (i == 0){
				stack <char> tmp;
				tmp.push(str[i]);
				piles.push_back(tmp);
				s = true;
			}
			for (int j = 0; j < piles.size(); j++){
				if (str[i] == piles[j].top()){
					piles[j].push(str[i]);
					s = true;
					break;
				}
			}
			if (!s){
				for (int j = 0; j < piles.size(); j++){
					if (str[i] < piles[j].top()){
						piles[j].push(str[i]);
						s = true;
						break;
					}
				}
			}
			if (!s){
				stack <char> tmp;
				tmp.push(str[i]);
				piles.push_back(tmp);
			}
		}

		q++;

		cout << "Case " << q << ": " << piles.size() << endl;
	}

	return 0;
}