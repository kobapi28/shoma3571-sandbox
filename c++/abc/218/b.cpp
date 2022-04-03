#include <iostream>
#include <string>
using namespace std;

int main() {
  string ans;
  for (int i=0; i<26; i++) {
    int p;
    cin >> p;
    ans += char('a' + p - 1);
  }

  cout << ans << endl;
}