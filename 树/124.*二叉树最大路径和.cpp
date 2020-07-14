/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (38.47%)	268	-
Tags
Companies
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

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
//递归就是先考虑根！！！
//本题相当于使用树的dp，要搞清楚情况。对于当前节点来说最大的一定是
//左中右结构，但是考虑到为上面的节点所用只能用单边桥
//学会用全局变量记录最优
//学会简化问题，只考虑最简单的二叉树来考虑这个问题
class Solution {
public:
    int globle = INT_MIN;
    int maxPath(TreeNode* root,int &val)
    {
        if(root==NULL)
            return 0;
        int left = max(maxPath(root->left,val),0);
        int right = max(maxPath(root->right,val),0);
        int situation1 = root->val+left+right;
        val = max(val,situation1);
        //注意这里一定要返回只走一条路径的情况，相当于返回的是单边路径的最大，才能被上面的父节点使用
        int onepath = root->val+max(left,right);
        return onepath;

    }
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPath(root,val);
        return val;
        
    }
};
