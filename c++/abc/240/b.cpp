#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  set<ll> st;
  for (int i=0; i<n; i++) {
    ll x;
    cin >> x;
    st.insert(x);
  }

  cout  << st.size() << endl;
}