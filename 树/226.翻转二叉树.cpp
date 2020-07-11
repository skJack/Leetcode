/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (73.24%)	417	-
Tags
Companies
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
//自己的方法是先傻逼呵呵的交换，再递归
//其实可以先做递归，然后直接交换
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
        else{
            TreeNode* left = invertTree(root->left);
            TreeNode* right = invertTree(root->right);
            TreeNode* tmp = root->left;
            root->left = right;
            root->right = left;
            
        }
        return root;

    }
};
