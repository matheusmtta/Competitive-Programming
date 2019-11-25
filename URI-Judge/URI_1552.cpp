#include <bits/stdc++.h>


using namespace std;

const int MAX = 501;

int sz[MAX], p[MAX], v[MAX], n, m;
vector <pair <double, pair <int , int> > > arr;

void build();
int find(int k);
void une(int a, int b);
double dist(double x1, double y1, double x2, double y2){
	int aux1 = x1-x2;
	int aux2 = y1-y2;
	aux1 *= aux1;
	aux2 *= aux2;
	return sqrt(aux1+aux2);
}

void build(){
	for (int i = 0; i < MAX; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(int k){
	if (k == p[k]) return k;
	return find(p[k]);
}

void une(int a, int b){
	a = find(a); b = find(b);
	if (b == a) return;
	if (sz[a] > sz[b])
		swap(a, b);
	sz[b] += sz[a];
	p[a] = b;
}

double kruskal(){
	build();
	sort(arr.begin(), arr.end());
	double sum = 0;

	for (int i = 0; i < (int) arr.size(); i++){
		double a = arr[i].second.first, b = arr[i].second.second;
		if (find(a) != find(b)){
			sum += arr[i].first;
			une(a, b);
		}
	}

	return sum;
}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		vector <pair <int, int>> axiscord;
		for (int i = 0; i < n; i++){
			int x, y; cin >> x >> y;
			axiscord.push_back(make_pair(x, y));
		}

		for (int i = 0; i < n-1; i++){
			for (int j = i + 1; j < n; j++){
				//cout << i << " " << j << endl;
				double ds = dist(axiscord[i].first, axiscord[i].second, axiscord[j].first, axiscord[j].second);
				arr.push_back(make_pair(ds, make_pair(i, j))); 
			}
		}

		double ans = kruskal()/100;

		printf("%.2lf\n", ans);

		for (int i = 0; i < MAX; i++)
			sz[i] = p[i] = v[i] = 0;

		arr.clear();
	}
}