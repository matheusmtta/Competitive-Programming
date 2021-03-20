#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int ans = 0;

//Largest rectangle area on a histogram routine
void solve(vector <int> heights){
    stack <int> sz, idx;
    
    heights.push_back(0);
    
    for (int i = 0; i < heights.size(); i++){
        int last_idx = INF;
        
        while (!idx.empty() && heights[i] < sz.top()){
            last_idx = idx.top();
            
            ans = max(ans, (i - last_idx) * sz.top());
            sz.pop();
            idx.pop();
        }
        
        if (sz.empty() || sz.top() < heights[i]){
            sz.push(heights[i]);
            idx.push(min(i, last_idx));
        }
    }
}

int main(){
	int n, m; cin >> n >> m;

	vector <vector<char>> matrix;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
    
    vector <int> heights(m, 0);
    
    for (int i = 0; i < m; i++)
        heights[i] = ((matrix[0][i] == '1') ? 1 : 0);
    
    solve(heights);
    
    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j] = 1 + heights[j];
        }
        solve(heights);
    }
    
    cout << ans << endl;

	return 0;
}