#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main() {
  int h,w,n;
  cin >> h >> w >> n;

  vector<int> a(n);
  vector<int> b(n);
  for (int i=0; i<n; i++) {
    cin >> a[i] >> b[i];
  }


  // 座標圧縮
  vector<int> a_sort_unique = a;
  vector<int> b_sort_unique = b;

  sort(a_sort_unique.begin(), a_sort_unique.end());
  sort(b_sort_unique.begin(), b_sort_unique.end());

  // 重複するものの削除
  a_sort_unique.erase(unique(a_sort_unique.begin(), a_sort_unique.end()), a_sort_unique.end());
  b_sort_unique.erase(unique(b_sort_unique.begin(), b_sort_unique.end()), b_sort_unique.end());

  for (int i=0; i<n; i++) {
    // 二分探索
    a[i] = lower_bound(a_sort_unique.begin(), a_sort_unique.end(), a[i]) - a_sort_unique.begin();
    b[i] = lower_bound(b_sort_unique.begin(), b_sort_unique.end(), b[i]) - b_sort_unique.begin();
  }

  for (int i=0; i<n; i++) {
    cout << a[i] + 1 << " " << b[i] + 1 << endl;
  }
}



// TLE
// int main() {
//   int h,w,n;
//   cin >> h >> w >> n;

//   set<int> hpos;
//   set<int> wpos;

//   vector<pair<int, int>> ab(n);
//   for (int i=0; i<n; i++) {
//     int a,b;
//     cin >> a >> b;
//     hpos.insert(a);
//     wpos.insert(b);
//     ab[i] = make_pair(a,b);
//   }

//   int hi = 1;
//   for (auto x: hpos) {
//     for (int i=0; i<n; i++) {
//       if (ab[i].first == x) {
//         ab[i].first = hi;
//       }
//     }
//     hi++;
//   }

//   int wi = 1;
//   for (auto x: wpos) {
//     for (int i=0; i<n; i++) {
//       if (ab[i].second == x) {
//         ab[i].second = wi;
//       }
//     }
//     wi++;
//   }

//   for (int i=0; i<n; i++) {
//     cout << ab[i].first << " " << ab[i].second << endl;
//   }
// }