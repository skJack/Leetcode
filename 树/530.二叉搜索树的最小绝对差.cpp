/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (54.87%)	124	-
Tags
Companies
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 
*/

class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int res = 100000;
        for(int i=1;i<ans.size();i++)
        {
            int tmp = ans[i] - ans[i-1];
            if(tmp<res)
                res = tmp;
        }
        return res;

    }
};
