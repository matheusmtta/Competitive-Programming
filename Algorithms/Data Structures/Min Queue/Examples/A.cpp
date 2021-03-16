#include <bits/stdc++.h>

using namespace std;

struct minQueue {
	stack <pair<int, int>> st1, st2;

	int getMax(){
		if (st1.empty() || st2.empty())
			return st1.empty() ? st2.top().second : st1.top().second;
		else
			return max(st1.top().second, st2.top().second);
	}

	void insert(int x){
		int mn = st1.empty() ? x : max(st1.top().second, x);
		st1.push({x, mn}); 
	}

	int popFront(){
		if (st2.empty()){
			while (!st1.empty()){
				int x = st1.top().first; st1.pop();
				int mn = st2.empty() ? x : max(x, st2.top().second);
				st2.push({x, mn});
			}
		}
		st2.pop();
	}

	int front(){
		if (st2.empty()){
			while (!st1.empty()){
				int x = st1.top().first; st1.pop();
				int mn = st2.empty() ? x : max(x, st2.top().second);
				st2.push({x, mn});
			}
		}

		return st2.top().first;
	}

	bool allow(){
		if (st1.empty() && st2.empty())
			return true;
		return false;
	}
};

int main(){
	int n, k; cin >> n >> k;
	vector <int> arr(n, 0);

	for (int &x : arr) 
		cin >> x;

	while (k--){
		int s; cin >> s;

		minQueue mq;

		for (int i = 0; i < s; i++)
			mq.insert(arr[i]);

		int ans = mq.getMax();
		for (int i = s; i < n; i++){
			mq.popFront();
			mq.insert(arr[i]);
			ans = min(ans, mq.getMax());
		}

		cout << ans << endl;
	}
}