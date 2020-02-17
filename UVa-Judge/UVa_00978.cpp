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
		int b, sb, sg;
		cin >> b >> sg >> sb;

		multiset<int, greater<int> > green, blue;

		for (int i = 0; i < sg; i++){
			int x; cin >> x;
			green.insert(x);
		}

		for (int i = 0; i < sb; i++){
			int y; cin >> y;
			blue.insert(y);
		}


		while (!blue.empty() && !green.empty()){
			queue <int> green_fighters, blue_fighters;

			int aux1 = green.size();
			int aux2 = blue.size();

			int sz = min(b, min(aux1, aux2));

			for (int i = 0; i < sz; i++){
				multiset<int, greater<int> >::iterator green_it = green.begin();
				multiset<int, greater<int> >::iterator blue_it = blue.begin();

				int verde_tmp, blue_tmp;

				verde_tmp = *green_it;
				blue_tmp = *blue_it;

				green.erase(green_it);
				blue.erase(blue_it);

				green_fighters.push(verde_tmp);
				blue_fighters.push(blue_tmp);
			}


			for (int i = 0; i < sz; i++){
				int verde, azul;

				verde = green_fighters.front();
				azul = blue_fighters.front();

				green_fighters.pop();
				blue_fighters.pop();


				if (verde == azul) continue;
				if (verde > azul)
					green.insert(verde-azul);
				else 
					blue.insert(azul - verde);
			}
		}

		if (blue.empty() && green.empty())
			cout << "green and blue died" << endl;
		else if (blue.empty()){
			cout << "green wins" << endl;
			for (auto i : green)
				cout << i << endl;
		}
		else{
			cout << "blue wins" << endl;
			for (auto i : blue)
				cout << i << endl;
		}

		if (t) cout << endl;
	}

	return 0;
}