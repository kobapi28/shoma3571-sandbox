#include <iostream>
#include <vector>
using namespace std;

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
    // テーブル
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    // 1 以上 N 以下の整数が素数かどうか
    return isprime;
}

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  vector<bool> isprime = Eratosthenes(201);

  for (int i = a; i <= b; i++) {
    bool TakahashiWin = true;
    for (int j = c; j <= d; j++) {
      if (isprime[i+j]) {
        // i+j が素数でないならiは使えないので、falseにする
        TakahashiWin = false;
      }
    }
    // iをすべて探索して、trueのままのものがあれば、それを出せば勝てる
    if (TakahashiWin) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }

  cout << "Aoki" << endl;
  return 0;
}