#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    unordered_map<int, int> first, last;

    // Find the first and last occurrences of each element.
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (!first.count(x)) first[x] = i;
      last[x] = i;
    }

    // Find the element that appears the most times in the array.
    int max_element = -1, max_count = 0;
    for (auto& [x, count] : last) {
      if (count - first[x] + 1 > max_count) {
        max_element = x;
        max_count = count - first[x] + 1;
      }
    }

    // Print the indices of the first and last occurrences of the element.
    cout << first[max_element] << " " << last[max_element] << endl;
  }

  return 0;
}
