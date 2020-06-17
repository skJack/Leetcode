/*
Category	Difficulty	Likes	Dislikes
algorithms	Medium (69.58%)	532	-
Tags
Companies
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？


*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<int>&ans,TreeNode* root)
    {
        if(root==NULL)
            return;
        else
        {
            dfs(ans,root->left);
            ans.push_back(root->val);
            dfs(ans,root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
};
