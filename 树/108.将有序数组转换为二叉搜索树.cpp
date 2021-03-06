/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (68.12%)	282	-
Tags
Companies
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

class Solution {
public:
    TreeNode* generator(vector<int>&nums,int begin,int end)
    {
        //思路：中序遍历的想法，找数组的中间作为根节点，左子树为中间的左半部分，右子树为中间的右半部分
        if(begin==end)
            return NULL;
        int mid = (begin+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left =  generator(nums,begin,mid);
        root->right =  generator(nums,mid+1,end);//注意边界
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return generator(nums,0,nums.size());
    }
};
