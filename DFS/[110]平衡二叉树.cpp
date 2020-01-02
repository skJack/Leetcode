
Category	Difficulty	Likes	Dislikes
algorithms	Easy (49.41%)	190	-
Tags
Companies
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
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
    bool flag = true; 
    int cal_height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = cal_height(root->left);
        int right = cal_height(root->right);
        return max(left,right)+1;//学会这种求最大深度的算法
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int left_height = cal_height(root->left);
        int right_height = cal_height(root->right);
        //cout<<left_height<<" "<<right_height<<endl;
        if(abs(left_height-right_height)>1)
        {
            return false;
        }
        else 
            return isBalanced(root->left)&&isBalanced(root->right);
    }
};
