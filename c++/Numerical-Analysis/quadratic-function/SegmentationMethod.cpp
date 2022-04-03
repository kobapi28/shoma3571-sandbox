// 割線法ソースコード

#include <iostream>
#include <math.h>
using namespace std;

// ここで扱う三次方程式
// (x-1.7)(x+3.75)(x-0.3) = 0
// 求める解は x = 0.3

// 三次方程式にxを代入したときのyを返す
double check(double x){
  return (x - 1.7) * (x + 3.75) * (x - 0.3);
}

int main() {
  // aが左端,bが右端
  double a, b;
  // 初期値の設定
  a = 0.9;
  b = 1;

  int index = 1;

  // 出力フォーマット
  cout << "n : [ a, b, 絶対誤差 ]" << endl;

  // index < 100 : 収束しない場合を考慮
  while (index < 100) {
    // 二点を結ぶ直線とx軸との交点
    double c = (check(b) * a - check(a) * b) / (check(b) - check(a));
    // 現在のaの値をbに代入、cの値をaに代入する
    b = a;
    a = c;
    // ↑ここでは、a > 0, b < 0で作成しているため。
    // 求める方程式によってはどちらを寄せるかが変わってくる。
    cout << index << " : [" << a << ", " << b << ", " << abs(0.3 - a) << "]" << endl;

    index++;

    // 10^-9 より小さくなったら、ループを抜ける
    if (abs(0.3 - a) < 0.000000001) break;
  }

  return 0;
}
