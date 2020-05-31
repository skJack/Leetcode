/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (49.20%)	538	-
Tags
Companies
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/

// @lc code=start
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
    bool dfs(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        if(left==NULL||right==NULL)
            return false;
        if(left->val!=right->val)
            return false;
        bool ans = dfs(left->left,right->right)&&dfs(left->right,right->left);
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return dfs(root->left,root->right);
    }
};
