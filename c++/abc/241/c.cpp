#include <bits/stdc++.h>
using namespace std;

int count(string str) {
  int c = 0;
  for (int i=0; i<6; i++) {
    if (str[i]=='#') c++;
  }
  return c;
}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);

  for (int i=0; i<n; i++) {
    cin >> s[i];
  }

  // 横の判定
  for (int i=0; i<n; i++) {
    for (int j=0; j<n-5; j++) {
      string text = s[i].substr(j,6);
      if (count(text) >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  // 縦の判定
  for (int i=0; i<n; i++) {
    string str = "";
    // textの生成
    for (int j=0;j<n; j++) {
      str += s[j][i];
    }

    for (int j=0; j<n-5; j++) {
      string text = str.substr(j,6);
      if (count(text) >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  // 斜め(左上から右下)の判定
  for (int i=0; i<n-5; i++) {
    for (int j=0; j<n-5; j++) {
      string str = "";
      for (int k=0; k<n; k++) {
        str += s[i+k][j+k];

        if (i+k == n-1 || j+k == n-1 ) break;
      }
      for (int j=0; j<str.length()-5; j++) {
      string text = str.substr(j,6);
      if (count(text) >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    }
  }

  // 斜め(右上から左下)の判定
  for (int i=0; i<n-5; i++) {
    for (int j=n-1; j>4; j--) {
      string str = "";
      for (int k=0;k<n;k++) {
        str += s[i+k][j-k];

        if (i+k == n-1 || j-k == 0) break;
      }
      for (int j=0; j<str.length()-5; j++) {
      string text = str.substr(j,6);
      if (count(text) >= 4) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    }
  }

  cout << "No" << endl;

}