叶子相似的树
Category	Difficulty	Likes	Dislikes
algorithms	Easy (61.57%)	42	-
Tags
Companies
Unknown

请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

提示：

给定的两颗树可能会有 1 到 100 个结点。
//思路：dfs访问叶子结点即可 判断两个vector是不是一样即可
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
    vector<int>ans1;
    vector<int>ans2;
    void dfs(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            ans.push_back(root->val);
            return;
        }
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,ans1);
        dfs(root2,ans2);
        for(int i=0;i<ans1.size();i++)
        {
            cout<<ans1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<ans2.size();i++)
        {
            cout<<ans2[i]<<" ";
        }
        //sort(ans1.begin(),ans1.end());
        //sort(ans2.begin(),ans2.end());
        return ans1==ans2;
    }
};
