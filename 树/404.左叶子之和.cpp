/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (52.91%)	166	-
Tags
Companies
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/

class Solution {
public:
//方法一：判断使用一个标志判断每个子节点是左孩子还是右孩子
    int hepler(TreeNode* root,bool is_left)
    {
        if(root==nullptr)
            return 0;
        if(!root->left&&!root->right)
        {
            //叶子结点
            if(is_left)
             return root->val;
        }
        int l = hepler(root->left,true);
        int r = hepler(root->right,false);
        return l+r;
    }
    int sumOfLeftLeaves1(TreeNode* root) {
        return(hepler(root,false));
    }
    //方法二：直接判断右边的叶子结点，感觉不如我的方法好
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(!root)
            return 0;
        if(root->left==NULL)
            return sumOfLeftLeaves(root->right);
        if(root->left->left==NULL&&root->left->right==NULL)
            //表示右节点为叶子结点
            return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);

    }
};
