#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  map<int, int> mp;
  for (int i=0; i<n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }

 for(int i=0; i<=2000; i++) {
   if (!mp.count(i)) {
     cout << i << endl;
     return 0;
   }
 }
}