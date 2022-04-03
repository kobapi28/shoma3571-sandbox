#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n,x;
  long long sum_a = 0;

  cin >> n;
  vector<long long> a(n);
  for (int i=0; i<n; i++){
    cin >> a[i];
    sum_a += a[i];
  }
  cin >> x;

  long long ans = (x / sum_a) * n;
  long long sum = sum_a * (x/sum_a);
  for (int i=0; i<n; i++) {
    sum += a[i];
    ans++;
    if (sum > x) {
      break;
    }
  }

  cout << ans << endl;
}