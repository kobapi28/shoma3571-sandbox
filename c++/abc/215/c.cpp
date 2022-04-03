#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
  string s;
  int k;
  cin >> s >> k;

  int count = 0;
  sort(s.begin(), s.end());

  do {
    count++;

    if (count == k) {
      cout << s << endl;
      return 0;
    }
  } while (next_permutation(s.begin(), s.end()));
}