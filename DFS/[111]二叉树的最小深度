二叉树的最小深度
Category	Difficulty	Likes	Dislikes
algorithms	Easy (40.74%)	185	-
Tags
Companies
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL&&root->right == NULL)//当前节点是叶子结点
            return 1;
        int left_height = minDepth(root->left);
        int right_height = minDepth(root->right);
        if(root->left == NULL)
        {
            return right_height+1;
        }
        if(root->right == NULL)
        {
            return left_height+1;
        }
        return min(left_height,right_height)+1;
    }
};
