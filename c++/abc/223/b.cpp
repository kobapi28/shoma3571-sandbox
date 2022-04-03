#include<iostream>
#include<string>
using namespace std;

int main() {
  string s;
  cin >> s;

  // 右シフトを1度行うことは左シフトをn-1回行うことと同じ
  // n回行うと元に戻る

  int n = size(s);
  string min_str = s;
  string max_str = s;

  for (int i=1; i<n; i++) {
    string sorted_str = s.substr(i, n-i) + s.substr(0, i);
    min_str = (min_str > sorted_str) ? sorted_str : min_str;
    max_str = (sorted_str > max_str) ? sorted_str : max_str;
  }

  cout << min_str << endl;
  cout << max_str << endl;

  return 0;
}