
Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.31%)	98	-
Tags
Companies
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
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
    vector<string>ans;
    void dfs(TreeNode* root,string s)
    {
        //直接遍历以后判断判断
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL)
        {
            //叶子节点
            s+=to_string(root->val);
            ans.push_back(s);
            return;
        }
        s+=to_string(root->val);
        dfs(root->left,s);
        dfs(root->right,s);

    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        string s = "";//可以换成int*10的做法
        dfs(root,s);
        int result = 0;
        for(int i=0;i<ans.size();i++)
        {
            int tmp = atoi(ans[i].c_str());
            cout<<tmp<<endl;
            result+=tmp;
        }
        return result;
        
    }
};
