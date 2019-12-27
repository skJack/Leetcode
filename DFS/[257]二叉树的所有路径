二叉树的所有路径
Category	Difficulty	Likes	Dislikes
algorithms	Easy (61.17%)	178	-
Tags
Companies
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

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
    vector<string>ans;
    void dfs(TreeNode* root,string s)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        s = s+"->";
        dfs(root->left,s);
        dfs(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        dfs(root,s);
        return ans;

    }
};
