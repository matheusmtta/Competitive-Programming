#include <bits/stdc++.h>

using namespace std;

struct minQueue {
	stack <pair<int, int>> st1, st2;

	int getMin(){
		if (st1.empty() || st2.empty())
			return st1.empty() ? st2.top().second : st1.top().second;
		else
			return min(st1.top().second, st2.top().second);
	}

	void insert(int x){
		int mn = st1.empty() ? x : min(st1.top().second, x);
		st1.push({x, mn}); 
	}

	void popFront(){
		if (st2.empty()){
			while (!st1.empty()){
				int x = st1.top().first; st1.pop();
				int mn = st2.empty() ? x : min(x, st2.top().second);
				st2.push({x, mn});
			}
		}
		st2.pop();
	}

	int front(){
		if (st2.empty()){
			while (!st1.empty()){
				int x = st1.top().first; st1.pop();
				int mn = st2.empty() ? x : min(x, st2.top().second);
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
	
}