#include <iostream>
#include <string>
using namespace std;

int main() {
  string s1,s2,s3,t;
  cin >> s1 >> s2 >> s3 >> t;

  string ans = "";

  for (int i=0; i<t.size(); i++) {
    char num = t[i];
    if(num=='1') {
      ans += s1;
    } else if(num=='2') {
      ans += s2;
    } else {
      ans += s3;
    }
  }

  cout << ans << endl;
  return 0;
}