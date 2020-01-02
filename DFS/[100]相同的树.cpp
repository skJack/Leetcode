相同的树
Category	Difficulty	Likes	Dislikes
algorithms	Easy (55.82%)	278	-
Tags
Companies
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false

题解一：
//将两个树的路径存储检查两个路径是否一样
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
    
    void dfs(TreeNode* o,vector<int>&tree)
    {
        
        if(o==NULL)
        {
            tree.push_back(-1);//碰到null说明有是单边桥的情况，就说明是null
            return;
        }
        tree.push_back(o->val);
        if(o->left==NULL&&o->right==NULL)
        {
            //叶子结点,就直接返回
            return;
        }
        dfs(o->left,tree);
        dfs(o->right,tree);

    }
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        vector<int>tree1;
        vector<int>tree2;
        dfs(p,tree1);
        dfs(q,tree2);
        if(tree1==tree2)
            return true;
        else
            return false;
    }
    //方法二：直接判断即可
    bool isSameTree(TreeNode* p, TreeNode* q) {//直接判断即可
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL||q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        bool ans = isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        return ans;
    }
};
