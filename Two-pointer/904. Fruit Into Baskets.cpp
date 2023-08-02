You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

// SOLUTION ---------------------------->>

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int res = 0;
        int l,r;
        int n = fruits.size();
        for(l=0,r=0;r<n;++r)
        {
            ++m[fruits[r]]; // couting each types of fruits
            // if types of fruits exceeds 2
            if(m.size()>2) //m.first.size()
            {
                // removing the type of fruit with lowest count
                if(--m[fruits[l]]==0)
                    m.erase(fruits[l]);

                ++l; // incrementing the idx
            }
            res=max(res,r-l+1); // current-> r-l+1 ------- res = prev
        }
        return res;
    }
};

//https://leetcode.com/problems/fruit-into-baskets/submissions/1010137644/
