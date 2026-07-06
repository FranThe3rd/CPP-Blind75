#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * We binary search on the eating speed k.
 * Lowest possible speed: 1 banana/hour.
 * Highest possible speed: max pile size.
 * For each k, calculate how many hours it takes:
 * hours += ceil(pile / k)
 * In C++, we can do:
 * hours += (pile + k - 1) / k;
 * If hours <= h, then this speed works, so try a smaller speed.
 * Otherwise, the speed is too slow, so try a larger speed.
 * Time Complexity: O(n log(maxPile))
 * Space Complexity: O(1)
 */

class Solution {
  public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int l = 1;
      int r = *max_element(piles.begin(), piles.end());
      int res = r;

      while (l <= r) {
        int k = l + (r - l) / 2;

        long long hours = 0;

        for (int p : piles) {
          hours += (p + k - 1) / k;
        }

        if (hours <= h) {
          res = k;
          r = k - 1;
        } else {
          l = k + 1;
        }
      }

      return res;
    }
};

int main() {
  Solution sol;
  vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h << endl);
    return 0;
}
