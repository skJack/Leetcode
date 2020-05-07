/*
Category	Difficulty	Likes	Dislikes
algorithms	Easy (42.46%)	244	-
Tags
Companies
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。


*/
class Solution {
public:
    bool check(TreeNode* s,TreeNode* t)
    {
        //判断两个子树是否完全一致
        if(s==NULL&&t==NULL)
        {
            return true;
        }
        if((s==NULL&&t!=NULL)||(s!=NULL&&t==NULL)||(s->val!=t->val))
            return false;

        bool l = check(s->left,t->left);
        bool r = check(s->right,t->right);
        return l&&r;
    }
    bool dfs(TreeNode* s,TreeNode* t)
    {
        if(s==NULL)
            return false;
        //判断两个树是否包含子树
        bool ans = check(s,t);//判断当前子树
        bool l = dfs(s->left,t);//判断左子树
        bool r = dfs(s->right,t);//判断右子树
        return ans||l||r;
    }
    //思路：暴力判断，和第100题很像
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
};
