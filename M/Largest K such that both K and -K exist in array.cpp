Given an array A of N integers, returns the largest integer K > 0 such that both values K and -K exist in array A. If there is no such integer, the function should return 0.

Example 1:
Input:[3, 2, -2, 5, -3]
Output: 3
Example 2:
Input:[1, 2, 3, -4]
Output: 0

// SOLUTION ----------------->>

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int largestK(vector<int> nums) {
  set<int> set;
  int curMax = 0;
  for (int a : nums) {
    if (set.count(-a))
      curMax = max(curMax, abs(a));
    else
      set.insert(a);
  }
  return curMax;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  int res = largestK(nums);
  cout << res << endl;
  return 0;
}

//https://algo.monster/problems/largest_k_positive_and_negative
