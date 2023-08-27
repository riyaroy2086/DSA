// You are given positive integers n and target.

// An array nums is beautiful if it meets the following conditions:

// nums.length == n.
// nums consists of pairwise distinct positive integers.
// There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
// Return the minimum possible sum that a beautiful array could have.

 

// Example 1:

// Input: n = 2, target = 3
// Output: 4
// Explanation: We can see that nums = [1,3] is beautiful.
// - The array nums has length n = 2.
// - The array nums consists of pairwise distinct positive integers.
// - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
// It can be proven that 4 is the minimum possible sum that a beautiful array could have.
// Example 2:

// Input: n = 3, target = 3
// Output: 8
// Explanation: We can see that nums = [1,3,4] is beautiful.
// - The array nums has length n = 3.
// - The array nums consists of pairwise distinct positive integers.
// - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
// It can be proven that 8 is the minimum possible sum that a beautiful array could have.
// Example 3:

// Input: n = 1, target = 1
// Output: 1
// Explanation: We can see, that nums = [1] is beautiful.
 

// Constraints:

// 1 <= n <= 105
// 1 <= target <= 105

// SOLUTION :

class Solution {
public:
    // ordered_set as average time complexity for inserting a element is O(logN) instead use unordered_set where insertion time is O(1)

    long long minimumPossibleSum(int n, int target) {
        unordered_set<int> s;
        long long res =0 , i=1;
        while(n)
        {
            if(!s.count(i))
            {
                s.insert(target-i);
                res+=i;
                n--;
            }
            i++;
            // if(s.find(target-1)== s.end())
            // {
            //     s.insert(i);
            //     res+=i;
            // }
        }
        return res;
    }
};  
