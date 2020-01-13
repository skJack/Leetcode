
Category	Difficulty	Likes	Dislikes
algorithms	Medium (28.07%)	355	-
Tags
Companies
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
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
    bool helper(TreeNode* root,int up,int down)
    {
        //方法一：保存节点的上界和下界，之后递归遍历即可。注意其中变化的小技巧
        if(root==NULL)
            return true;
        //规定当前节点的上界和下界
        if(up!=5050&&root->val>=up)
            return false;
        if(down!=-5050&&root->val<=down)
            return false;
        if(!helper(root->left,root->val,down))
            return false;
        if(!helper(root->right,up,root->val))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        cout<<NULL;
       return helper(root,5050,-5050);
    }
};
