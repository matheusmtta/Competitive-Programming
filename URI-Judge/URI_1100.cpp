#include <bits/stdc++.h>

using namespace std;

int xm[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ym[8] = {2, 1, -1, -2, -2, -1, 1, 2};

bool all (int x, int y){
	if (x > 7 || x < 0) return 0;
	if (y > 7 || y < 0) return 0;
	return 1;
}

int mtx[8][8];

void BFS(pair <int, int> xy, pair <int, int> dd){
	queue <pair <int, int> > fila;
	set <pair <int, int> > used;

	used.insert(xy);
	fila.push(xy);
	mtx[xy.first][xy.second] = 0;

	while(!fila.empty()){
		pair <int, int> v = fila.front();
		fila.pop();

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

int main (){
	std::string a, b;
	while(cin >> a >> b){
		int x, y, d1, d2;
		x = a[0] - 'a';
		y = a[1] - '1';
		d1 = b[0] - 'a';
		d2 = b[1] - '1';

		if (a == b) {cout << "To get from " << a << " to " << b << " takes " << mtx[d1][d2] << " knight moves." << endl; continue;}

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				mtx[i][j] = 0;

		pair <int, int> xy;
		pair <int, int> dd;
		dd = make_pair(d1, d2);
		xy = make_pair(x, y);

		BFS(xy, dd);

		cout << "To get from " << a << " to " << b << " takes " << mtx[d1][d2] << " knight moves." << endl;
	}
}