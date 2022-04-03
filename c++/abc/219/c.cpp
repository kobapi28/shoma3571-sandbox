#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  string str;
  int n;

  cin >> str >> n;
  vector<string> s(n);

  vector<int> position(26);
  for (int i=0; i<26; i++) {
    position[str[i] - 'a'] = i;
    // 0(a)-> 5, 1(b)-> 2 みたいな配列ができあがる 
  }

  for (int i=0; i<n; i++) {
    cin >> s[i];
  }

  sort(s.begin(), s.end(), [&](const string& a, const string& b) {
    // 文字列の比較
    int len = min(a.size(), b.size());
    for (int i=0; i<len; i++) {
      // もし値が違ったら
      if (a[i]!=b[i]) {
        // 
        return position[a[i] - 'a'] < position[b[i] - 'a'];
      }
    }

    // どちらかの長さまで同じだったとき
    return a.size() < b.size(); 
  });


  for (int i=0; i<n; i++) {
    cout << s[i] << endl;
  }

  return 0;
}