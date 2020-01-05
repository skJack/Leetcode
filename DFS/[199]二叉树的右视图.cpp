二叉树的右视图
Category	Difficulty	Likes	Dislikes
algorithms	Medium (62.37%)	120	-
Tags
Companies
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
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
    vector<vector<int>> number;
    void dfs(TreeNode* root,vector<int>tmp)
    {
        if(root==NULL)
            return;
        tmp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            number.push_back(tmp);
        }
        dfs(root->right,tmp);
        dfs(root->left,tmp);
    }
    vector<int> rightSideView1(TreeNode* root) {
        //方法一：最笨的方法，把所有的节点都保存下来，然后遍历二维数组做判断
        vector<int>tmp;
        vector<int>ans;
        if(root==NULL)
            return ans;
        
        dfs(root,tmp);//将每一个路的节点都存起来再做取舍
        for(int i=0;i<number.size();i++)
        {
            for(int j=0;j<number[i].size();j++)
            {
                cout<<number[i][j]<<" ";
            }
            cout<<endl;
        }
        ans = number[0];
        int j=number[0].size();
        for(int i=0;i<number.size()-1;i++)
        {
            for(int k=j;k<number[i+1].size();k++)
            {
                ans.push_back(number[i+1][k]);
                j = number[i+1].size();
            }
        }
        return ans;
    }
    void dfs1(TreeNode* root,int height,vector<int>&res)
    {
        //聪明的方法1：每次遍历时只要判断当前数组的元素个数和树高的关系即可
        if(root==NULL)
            return;
        if(height==res.size())
            res.push_back(root->val);
        dfs1(root->right,height+1,res);//注意先遍历右节点
        dfs1(root->left,height+1,res);//遍历完右节点之后判断左节点是否加入就是判断是否等于数组大小
    }
    vector<int> rightSideView2(TreeNode* root) {
        vector<int>res;
        dfs1(root,0,res);
        return res;
    }
    vector<int> rightSideView(TreeNode* root) {
        //bfs遍历
        vector<int>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            res.push_back(q.back()->val);//注意队尾的就是最右边的，所以要从左往右遍历
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* t= q.front();q.pop();
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
            }
        }
        return res;
    }
};
