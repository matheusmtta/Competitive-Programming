#include <bits/stdc++.h>

using namespace std;

bool detectColision(int x0, int x1, int y0, int y1, int r, int cx, int cy){
  if ((cy >= y0 && cy < y1) || (cy > y0 && cy <= y1)){
    if ((cx <= x1 && cx > x0) || (cx < x1 && cx >= x0)) return true;
    if (cx > x1 && cx-r <= x1) return true;
    if (cx < x0 && cx+r >= x0) return true;
    else return false;
  }
  else if ((cx >= x0 && cx < x1) || (cx > x0 && cx <= x1)){
    if ((cy <= y1 && cy > y0) || (cy < y1 && cy >= y0)) return true;
    else if (cy > y1 && cy-r <= y1) return true;
    else if (cy < y0 && cy+r >= y0) return true;
    else return false;
  }
  else if (cx > x1 && cy > y1) {
    if (sqrt((pow(cx-x1, 2))+(pow(cy-y1, 2))) <= r) return true;
    else return false;
  }
  else if (cx < x0 && cy > y1) {
    if (sqrt((pow(cx-x0, 2))+(pow(cy-y1, 2))) <= r) return true;
    else return false;
  }
  else if (cx < x0 && cy < y0){
    if (sqrt((pow(cx-x0, 2))+(pow(cy-y0, 2))) <= r) return true;
    else return false;
  }
  else if (cx > x1 && cy < y0) {
    if (sqrt((pow(cx-x1, 2))+(pow(cy-y0, 2))) <= r) return true;
    else return false;
  }
  //cout << "none colision" << endl;
  return false;
}

int main(){
  int x0, y0, h, w, c0, c1, r, x1, y1, damage=0, n, lv;
  string type;
  cin >> n;
  while(n--){
    cin >> w >> h >> x0 >> y0;
    cin >> type >> lv >> c0 >> c1;
    if (type == "fire"){
      damage = 200;
      if (lv == 1) r = 20;
      else if (lv == 2) r = 30;
      else if (lv == 3) r = 50;
      x1 = x0+w;
      y1 = y0+h;
      detectColision(x0, x1, y0, y1, r, c0, c1) ? cout << damage << endl : cout << 0 << endl;
    }
    else if (type == "water"){
      damage=300;
      if (lv == 1) r = 10;
      else if (lv == 2) r = 25;
      else if (lv == 3) r = 40;
      x1 = x0+w;
      y1 = y0+h;
      detectColision(x0, x1, y0, y1, r, c0, c1) ? cout << damage << endl : cout << 0 << endl;
    }
    else if (type == "earth"){
      damage=400;
      if (lv == 1) r = 25;
      else if (lv == 2) r = 55;
      else if (lv == 3) r = 70;
      x1 = x0+w;
      y1 = y0+h;
      detectColision(x0, x1, y0, y1, r, c0, c1) ? cout << damage << endl : cout << 0 << endl;
    }
    else if (type == "air"){
      damage=100;
      if (lv == 1) r = 18;
      else if (lv == 2) r = 38;
      else if (lv == 3) r = 60;
      x1 = x0+w;
      y1 = y0+h;
      detectColision(x0, x1, y0, y1, r, c0, c1) ? cout << damage << endl : cout << 0 << endl;
    }
  }
  return 0;
}
