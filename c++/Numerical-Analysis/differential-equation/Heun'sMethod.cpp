#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
 * ここで与える式 
 * y' = 3ty
 * 初期条件 y(0) = 3
 * 解析解 y = 3e^(1.5t^2)
 */

// 刻み幅h
const double h = 0.1; 

double dy(double t, double y) {
  return 3 * t * y;
}

int main() {
  // 秒数
  cout << "秒数の入力(整数)" << endl;
  int t;
  cin >> t;

  // 初期値3なので
  double y = 3;
  for (int i=1; i<=t*(1/h); i++) {
    // ホイン法
    y = y + (h/2) * (dy(i*h-h,y) + dy(i*h,y));
    cout << left << setw(5) << i*h;
    cout << y << endl;
  }
}