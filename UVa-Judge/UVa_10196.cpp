#include <bits/stdc++.h>

/*
bbbbbbbb
bbbbbbbb
........
........
........
........
WWWWWWWW
WWWWWWWW
*/

using namespace std;

//trivial directions
int move_x[8] = {0, 1, 1,  1,  0, -1,-1,-1};
int move_y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

//horse directions
int horse_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int horse_y[8] = {2, 1,-1,-2, -2, -1,  1,  2};

//rook directions
int rook_x[4] = {0, 1, 0, -1};
int rook_y[4] = {1, 0, -1, 0};

//bishop directions
int bishop_x[4] = {1, 1, -1, -1};
int bishop_y[4] = {1, -1, -1, 1};

char table[8][8];
pair <int, int> king_w, king_b;

bool allow(int x, int y){
	if (x > 7 || x < 0) return false;
	else if (y > 7 || y < 0) return false;
	return true;
}

int check_white(){
	int x, y, k, l;
	x = king_w.first;
	y = king_w.second;
	//CHECK PAWN
	if (allow(x-1, y+1) && table[x-1][y+1] == 'p'){
		return true;
	}
	if (allow(x-1, y-1) && table[x-1][y-1] == 'p'){
		return true;
	}
	//CHECK HORSE
	for (int i = 0; i < 8; i++){
		if (allow(x+horse_x[i], y+horse_y[i]) 
			&& table[x+horse_x[i]][y+horse_y[i]] == 'n')
		 return true;
	}
	//CHECK ROOK & QUEEN
	for (int i = 0; i < 4; i++){
		k = x; l = y;
		k += rook_x[i];
		l += rook_y[i];
		while (allow(k, l)){
			if (table[k][l] == 'r' || table[k][l] == 'q') return true;
			else if (table[k][l] != '.') break;
			k += rook_x[i];
			l += rook_y[i];
		}
	}
	//CHECK BISHOP & QUEEN
	for (int i = 0; i < 4; i++){
		k = x; l = y;
		k += bishop_x[i];
		l += bishop_y[i];
		while (allow(k, l)){
			if (table[k][l] == 'b' || table[k][l] == 'q') return true;
			else if (table[k][l] != '.') break;
			k += bishop_x[i];
			l += bishop_y[i];
		}
	}

	return false;
}

bool check_black(){
	int x, y, k, l;
	x = king_b.first;
	y = king_b.second;
	//CHECK PAWN
	if (allow(x+1, y-1) && table[x+1][y-1] == 'P'){
		return true;
	}
	if (allow(x+1, y+1) && table[x+1][y+1] == 'P'){
		return true;
	}
	//CHECK HORSE
	for (int i = 0; i < 8; i++){
		if (allow(x+horse_x[i], y+horse_y[i]) 
			&& table[x+horse_x[i]][y+horse_y[i]] == 'N')
		 return true;
	}
	//CHECK ROOK & QUEEN
	for (int i = 0; i < 4; i++){
		k = x; l = y;
		k += rook_x[i];
		l += rook_y[i];
		while (allow(k, l)){
			if (table[k][l] == 'R' || table[k][l] == 'Q') return true;
			else if (table[k][l] != '.') break;
			k += rook_x[i];
			l += rook_y[i];
		}
	}
	//CHECK BISHOP & QUEEN
	for (int i = 0; i < 4; i++){
		k = x; l = y;
		k += bishop_x[i];
		l += bishop_y[i];
		while (allow(k, l)){
			if (table[k][l] == 'B' || table[k][l] == 'Q') return true;
			else if (table[k][l] != '.') break;
			k += bishop_x[i];
			l += bishop_y[i];
		}
	}

	return false;
}

int main(){
	int n = 1;
	while (1){
		int stop = 0;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				cin >> table[i][j];
				if (table[i][j] == '.') stop += 1;
				else if (table[i][j] == 'K') {king_w.first = i; king_w.second = j;}
				else if (table[i][j] == 'k') {king_b.first = i; king_b.second = j;}
			}
		}	
		if (stop == 64) return 0;

		bool ans1 = false, ans2 = false;

		ans1 = check_white();
		ans2 = check_black(); 

		if (ans2) printf("Game #%d: black king is in check.\n", n);
		else if (ans1) printf("Game #%d: white king is in check.\n", n);
		else printf("Game #%d: no king is in check.\n", n);
		n++;
	}

	return 0;
}