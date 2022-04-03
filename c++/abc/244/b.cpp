#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  string t;
  cin >> n >> t;

  // 位置の座標
  int x,y;
  x = 0; y = 0;

  char muki = 'E';
  for (int i=0; i<n; i++) {
    if (t[i] == 'S') {
      // 1だけ進む。
      if (muki == 'N') {
        y++;
      } else if (muki == 'E') {
        x++;
      } else if (muki == 'S') {
        y--;
      } else {
        x--;
      }
    } else {
      // 向きの変更
      if (muki == 'N') {
        muki = 'E';
      } else if (muki == 'E') {
        muki = 'S';
      } else if (muki == 'S') {
        muki = 'W';
      } else {
        muki = 'N';
      }
    }
  }

  cout << x << " " << y << endl;
}