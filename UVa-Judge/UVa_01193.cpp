#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
#define mp make_pair
#define pb push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const double e = 1e-9;

double n, d;
vector <pair<double, double>> arr;

double sqrtd (double a, double b) {
	return sqrt(a*a - b*b);
}

bool compare(const pair<double,double> &a, const pair<double,double> &b){
	if (abs(a.first - b.first) > e){
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q = 1;

	while (cin >> n >> d){
		if (n == 0 && d == 0) return 0;
		bool flag = true;

		for (int i = 0; i < n; i++){
			double x, y;
			cin >> x >> y;
			if (y > d) flag = false;
			arr.push_back({x-sqrtd(d, y), x+sqrtd(d, y)});
		}

		sort(arr.begin(), arr.end(), compare);

		double lst = -INF;
		int idx = 0;
		int ans = 0;

		while (idx < n && flag){
			while (idx < n && arr[idx].first <= lst){
				lst = min(arr[idx].second, lst);
				idx++;
			}
			ans++;
			lst = arr[idx].second;
		}

		ans--;

		cout << "Case " << q << ": ";
		flag ? cout << ans << endl : cout << -1 << endl;

		arr.clear();
		q++;
	}

	return 0;
}