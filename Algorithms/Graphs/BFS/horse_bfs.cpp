#include <bits/stdc++.h>

using namespace std;

//COMPLEXITY O(N + M)

//VECTOR OF POSSIBLE HORSE MOVEMENTS OVER THE BOARD
int xm[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ym[8] = {2, 1, -1, -2, -2, -1, 1, 2};

//TEST IF THE HORSE GO OUT OF THE BOARD
bool all (int x, int y){
	if (x > 7 || x < 0) return 0;
	if (y > 7 || y < 0) return 0;
	return 1;
}

//SAVE THE DISTANCE TO GET FROM <X, Y> TO <D_i, D_j>
int mtx[8][8];

//RECEIVES THE ORGIN AND THE DESTINY OF THE HORSE
void BFS(pair <int, int> xy, pair <int, int> dd){
	queue <pair <int, int> > fila;
	set <pair <int, int> > used;

	used.insert(xy);
	fila.push(xy);
	mtx[xy.first][xy.second] = 0;

	while(!fila.empty()){
		pair <int, int> v = fila.front();
		fila.pop();
		//ITERATE OVER THE MOVEMENT VECTOR, AND CHECK IF
		//THE MOVEMENT IS ALLOWED
		for (int i = 0; i < 8; i++){
			int nx = v.first+xm[i], ny = v.second+ym[i];
			if (all(nx, ny)){
				mtx[nx][ny] = mtx[v.first][v.second] + 1;
				pair <int, int> u = make_pair(nx, ny);
				if (u == dd) return;
				fila.push(u);
			}
		}
	}
}