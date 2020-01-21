#include <bits/stdc++.h>

using namespace std;

struct info{
	string name;
	int base;
	int bytes;
	int dimensions;
	vector <pair <int, int >> luBounds;
};


int main(){
	map <string, info> data;
	int N, R; cin >> N >> R;
	for (int i = 0; i < N; i++){
		info tmp;
		cin >> tmp.name;
		cin >> tmp.base;
		cin >> tmp.bytes;
		cin >> tmp.dimensions;
		tmp.luBounds.push_back(make_pair(0, 0));

		for (int j = 0; j < tmp.dimensions; j++){
			int l, u; cin >> l >> u;
			tmp.luBounds.push_back(make_pair(l, u));
		}

		data.insert({tmp.name, tmp});
	}

	for (int k = 0; k < R; k++){
		string tmp; cin >> tmp;
		int dim = data[tmp].dimensions;

		int idx[dim+1];

		string phr;

		phr = tmp;

		phr += "[";

		for (int j = 0; j < dim; j++){
			cin >> idx[j+1];
			//cout << idx[j+1] << " ";
			if (j == dim-1)
				phr += to_string(idx[j+1]) + "] = ";
			else
				phr += to_string(idx[j+1]) + ", ";
		}

		int B = data[tmp].base;
		int S = data[tmp].bytes;

		int C[dim+1];

		C[dim] = S;

		int count = dim;

		//cout << tmp << endl;

		while (count --){
			int upper = data[tmp].luBounds[count+1].second;
			int lower = data[tmp].luBounds[count+1].first;
			C[count] = C[count+1]*(upper - lower + 1);
		}

		C[0] = B;

		for (int i = 1; i < dim+1; i++)
			C[0] -= (data[tmp].luBounds[i].first * C[i]);

		int ans = 0;

		for (int i = 1; i < dim+1; i++){
			ans += (idx[i] * C[i]);
		}

		ans += C[0];

		cout << phr << ans << endl;
	}

	return 0;
}