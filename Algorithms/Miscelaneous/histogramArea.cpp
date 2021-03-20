#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int main(){
	int n; cin >> n;
	vector <int> height(n, 0);

	for (int &x : height)
		cin >> x;

	height.push_back(0);

	stack <pair<int, int>> st;

	int ans = 0;

	for (int i = 0; i < (int)height.size(); i++){
		int lastIdx = INF;
		while (!st.empty() && height[i] < st.top().second){
			lastIdx = st.top().first;
			int currArea = (i - lastIdx) * st.top().second;
			
			st.pop();

			ans = max(currArea, ans);
		}

		if (st.empty() || height[i] > st.top().second)
			st.push({min(i, lastIdx), height[i]});
	}

	cout << ans << endl;
}