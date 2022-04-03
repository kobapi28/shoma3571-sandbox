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
    // ルンゲクッタ法
    double k1 = h * dy(i*h-h, y);
    double k2 = h * dy(i*h-(h/2), y + (k1/2));
    double k3 = h * dy(i*h-(h/2), y + (k2/2));
    double k4 = h * dy(i*h, y+k3);
    // cout << k1 << " " << k2 << " " << k3 << " " << k4 << endl;
    y = y + (k1+ 2*k2 + 2*k3 + k4) / 6;
    cout << left << setw(5) << i*h;
    cout << y << endl;
  }
}