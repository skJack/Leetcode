/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (57.64%)	313	-
Tags
Companies
amazon

给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
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
    int sums = 0;
    void dfs(TreeNode* root,bool calsum)
    //中序遍历树，calsum为计算总和还是
    {
        if(root==NULL)
            return;
        dfs(root->left,calsum);
        if(calsum)
            sums+=root->val;
        else
        {
            int tmp = root->val;
            root->val = sums;
            sums = sums - tmp;
        }
        
        dfs(root->right,calsum);
    }
    void dfs2(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs2(root->right);
        sums+=root->val;
        root->val = sums;
        
        dfs2(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        //方法一：先计算一遍总和，再从左往右遍历修改。但其实直接从右往左遍历就可以只遍历一次
       //搜索二叉树想要从大到小排序，只要左右换一下就行
        //dfs(root,true);
        //dfs(root,false);
        dfs2(root);

        return root;
    }
};
