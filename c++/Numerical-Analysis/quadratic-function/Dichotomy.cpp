// 二分法ソースコード

#include <iostream>
#include <math.h>
using namespace std;

// ここで扱う三次方程式
// (x-1.7)(x+3.75)(x-0.3) = 0
// 求める解は x = 0.3

// 三次方程式にxを代入したときに、それが正ならtrue, 負ならfalseを返す
bool check(double x) {
    double ans = (x-1.7)*(x+3.75)*(x-0.3);
    return ans > 0;
}



int main() {
    // aが左端,bが右端
    double a,b;
    // 初期値の設定
    a = 0; b = 1;

    int index = 1;

    // 出力フォーマット
    cout << "n : [ a, b, 絶対誤差 ]" << endl;

    // 掛け算が = 0 
    // つまり、どちらかが正でどちらかが負のとき
    // index < 100 : 収束しない場合を考慮
    // 10^-9 より小さくなったら、ループを抜ける
    while (!(check(a) * check(b)) && index < 100 && abs(a-0.3) > 0.000000001) {
        // 中間点の算出
        double c = (a + b) / 2;
        if (check(c)) {
            // もし正なら
            a = c;
        } else {
            // もし負なら
            b = c;
        }
        // ↑ここでは、a > 0, b < 0で作成しているため。
        // 求める方程式によってはどちらを寄せるかが変わってくる。
        cout << index << " : [" << a << ", " << b << ", " << abs(0.3-(a+b)/2) << "]" << endl;

        index++;
    }

    return 0;
}
