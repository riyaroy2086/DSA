40. Combination Sum II
Medium

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(),candidates.end());
        // 1 1 2 5 6 
        // int mini = INT_MAX;
        vector<vector<int>> v;
        vector<int> st;
        combination(0,target,candidates,v,st);
        return v;
    }

    void combination(int idx,int target,vector<int>&arr,vector<vector<int>>&v , vector<int>&st)
    {
        if(target==0)
        {
            v.push_back(st);
            return;
        }

        for(int i=idx;i<arr.size();++i)
        {
            if(i>idx && arr[i]==arr[i-1]) 
                continue;

            if(arr[i]>target)
                break;

            st.push_back(arr[i]); 
            combination(i+1,target-arr[i],arr,v,st);
            st.pop_back(); //keeping it empty for the next arr[i]  
        }
    }
};

//https://leetcode.com/problems/combination-sum-ii/submissions/988824421/