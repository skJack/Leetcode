/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (67.75%)	150	-
Tags
Companies
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？


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
    vector<int>permute;
    int index=0;
    int ans;
    bool find = false;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        permute.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest1(TreeNode* root, int k) {
        inorder(root);
        return permute[k-1];
    }
    //方法二:dfs剪枝，主要是学会dfs的早停方法，在返回的时候判断一下全局变量
    void helper(TreeNode* root,int k)
    {
        if(root==NULL||find==true)
            return;
        helper(root->left,k);
        if(++index == k)
            {
                ans = root->val;
                find = true;
            }
        helper(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return ans;
    }
};
