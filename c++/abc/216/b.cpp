#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> mp;
  int n;
  cin >> n;

  for(int i=0; i<n; i++) {
    string s,t;
    cin >> s >> t;
    mp[s+" "+t]++;
  }

  if (mp.size() == n) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}