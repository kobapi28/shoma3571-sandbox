#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  string s1,s2,s3,t1,t2,t3;
  cin >> s1 >> s2 >> s3;
  cin >> t1 >> t2 >> t3;

  // 全て違う場合
  if (s1 != t1 && s2 != t2 && s3 != t3) {
    cout << "Yes" << endl;
  } else if (s1 == t1 && s2 == t2 && s3 == t3) {
    // 全て同じ場合はそのまま
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
} 