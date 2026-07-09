#include <vector>
#include <iostream>
#include <algorithm>


/**
 * You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.
 * You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.
 * Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.
 * Example 1:
 * Input: prices = [10,1,5,6,7,1]
 * Output: 6
 *
 * So first thing we do we initialize left to 0 and right to one, and we have a variable to keep track
 * of max profit. We also iterate through the prices array with a while loop until r is at the end of the loop.
 * If the prices on left side smaller than right, thats good we have a profit so we calculate it. If we don't then
 * we set left to the right spot, and right will continue moving on. We return max proft in the end
 *
 */


int bestTimeBuySellStock(std::vector<int>& prices) {
  int maxP = 0;
  int l = 0;
  int r = 1;

  while (r < prices.size()) {
    if (prices[l] < prices[r]) {
      int profit = prices[r] - prices[l];
      maxP = std::max(maxP,profit);
    }
    else {
      l = r;
    }
    r +=1;
  }
  return maxP;

}


int main() {
  std::vector<int> prices = {10,1,5,6,7,1};
  int result = bestTimeBuySellStock(prices);
  std::cout << result;

}
