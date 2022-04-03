// ニュートン法ソースコード

#include <iostream>
#include <math.h>
using namespace std;

// ここで扱う三次方程式
// (x-1.7)(x+3.75)(x-0.3) = 0
// 求める解は x = 0.3

// 接線の値
double tangentLine(double x) {
  return 3*pow(x, 2) + 3.5*x - 6.99;
}

// 三次方程式にxを代入したときのyを返す
double check(double x){
  return (x - 1.7) * (x + 3.75) * (x - 0.3);
}

int main() {
  double a;
  // 初期値の設定
  a = 0.5;

  int index = 1;

  // 出力フォーマット
  cout << "n : [ a, 絶対誤差 ]" << endl;

  // index < 100 : 収束しない場合を考慮
  while (index < 100) {
    // 二点を結ぶ直線とx軸との交点
    a = a - (check(a) / tangentLine(a));


    cout << index << " : [" << a << ", " << abs(0.3 - a) << "]" << endl;

    index++;

    // 10^-9 より小さくなったら、ループを抜ける
    if (abs(0.3 - a) < 0.000000001) break;
  }

  return 0;
}
