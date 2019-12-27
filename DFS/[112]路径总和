路径总和
Category	Difficulty	Likes	Dislikes
algorithms	Easy (48.38%)	208	-
Tags
Companies
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    int current = 0;
    bool flag = false;
    void dfs(TreeNode* root,int sum,int current)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            //叶子结点
            if(current+root->val==sum)
                {
                    flag = true;
                }
            return;
        }
        dfs(root->left,sum,current+root->val);
        dfs(root->right,sum,current+root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
       dfs(root,sum,0);
       return flag;     
    }
};
