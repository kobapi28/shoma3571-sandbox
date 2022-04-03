#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//
// ACできていない...
//

// 0-> 引き分け
// 1-> 前者勝ち
// 2-> 後者勝ち 
char judge(char a, char b){
  if (a==b) return '0';
  if(a=='G' && b=='C') return '1';
  if(a=='C' && b=='P') return '1';
  if(a=='P' && b=='G') return '1';
  else return '2';
}

int main(){
  int n, m;
  cin >> n >> m;

  // 2n*mの配列の宣言
  vector<vector<char>> a(2 * n, vector<char>(m));

  for (int i = 0; i < 2 * n; i++){
    for (int j = 0; j < m; j++){
      cin >> a.at(i).at(j);
    }
  }

  // もう対戦したかを判断する
  vector<vector<bool>> isPlayed(2 * n, vector<bool>(2 * n));
  // 初期化
  for (int i = 0; i < 2 * n; i++){
    for (int j = 0; j < 2 * n; j++){
      a.at(i).at(j) = false;
    }
  }

  // 勝った数を数える変数の定義
  vector<pair<int, int>> count(2 * n);
  // 初期化
  for (int i = 0; i < 2 * n; i++){
    // count, id
    count[i] = make_pair(0, i);
  }


  // m回繰り返す
  // iは勝負の回数を指し示す
  for (int i = 0; i < m; i++){
    // countは降順で、idは昇順でsort
    sort(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b){ 
      return a.first > b.first || (a.first == b.first && a.second < b.second);
    });

    // この会において、相手が存在するかどうか
    // 人数分の1次元配列
    vector<bool> isDecided(2*n, false);

    // 相手を確定させる。そして勝者のカウントを+1する
    // jはユーザーを指し示す
    for(int j=0; j< 2*n; j++) {
      // 対戦者が決まっていればスキップ
      if(isDecided.at(j)) continue;

      // kは相手ユーザーを指し示す
      for(int k=j+1; k<2*n; k++) {
        // これまでに対戦していないかつこの会の対戦者が決まっていない
        if(!isPlayed.at(j).at(k) && !isDecided.at(k)) {
          isDecided.at(j) = true; isDecided.at(k) = true;
          isPlayed.at(j).at(k) = true; isPlayed.at(k).at(j) = true;

          char result = judge(a.at(j).at(i), a.at(k).at(i));

          if(result == '1') count[j].first++;
          else if (result == '2') count[k].first++;
        }
      }
    }
  }

  // 最終出力
  for (pair<int, int> x : count){
    // idのみの出力
    cout << x.second << endl;
  }

}