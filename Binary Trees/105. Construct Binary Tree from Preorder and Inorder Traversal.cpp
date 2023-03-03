//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/908456354/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map <int,int> map;
        for(int i=0;i<inorder.size();i++)
            map[inorder[i]] = i; // mapping is done here
        return split(preorder,map,0,0,inorder.size()-1);    
    }

    TreeNode* split(vector<int> &preorder,unordered_map <int,int>& map,int idx,int left,int right)
    {
        int val = preorder[idx]; // curr idx
        int mid = map[val]; // root->val is val

        TreeNode *root = new TreeNode(val);
        // divide and conquer
        if(mid>left)
            root->left = split(preorder,map,idx+1,left,mid-1);
        if(mid<right)
            root->right = split(preorder,map,idx+mid-left+1,mid+1,right);

        return root;    
    }
};