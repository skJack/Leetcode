路径总和 II
Category	Difficulty	Likes	Dislikes
algorithms	Medium (57.95%)	145	-
Tags
Companies
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

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
    vector<vector<int>> ans;
    bool flag = false;
    void dfs(TreeNode* root,int sum,int &current,vector<int>&now)
    {
        if(root==NULL)
            return;
        now.push_back(root->val);
        current += root->val;
        //cout<<root->val<<" "<<current<<endl;
        if(root->left==NULL&&root->right==NULL&&current==sum)
        {
            //叶子结点
            {
                //now.push_back(root->val);
                ans.push_back(now);
                //now.clear();
            }
            return;
        }
        dfs(root->left,sum,current,now);
        dfs(root->right,sum,current,now);
        now.pop_back();
        current -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>now;
        int current = 0;
        dfs(root,sum,current,now);
        return ans;
    }
};
