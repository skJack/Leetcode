/*
平衡二叉树
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

*/
//思路：首先必须会写最大深度，然后遍历每个子节点的左右子树的最大深度就行
class Solution {
public:
    int maxlen(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(maxlen(root->left),maxlen(root->right))+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(abs(maxlen(root->right)-maxlen(root->left))>1)
            return false;
        else
            return isBalanced(root->left)&&isBalanced(root->right);
    }
};
