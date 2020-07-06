/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (63.44%)	298	-
Tags
Companies
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？


*/

class Solution {
public:
    vector<int>ans;
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode *tmp=root;
        while (tmp!=NULL||!s.empty())
        {
            while (tmp!=NULL)//当栈顶元素不为空的时候，则做三件事
            //1.当前元素加入结果数组
            //2.把当前元素的右子树加入到栈中（利用了栈后进先出的性质）
            //3.指针向左子树移动（先左后右）
            {
                ans.push_back(tmp->val);
                s.push(tmp->right);
                tmp = tmp->left;
            }
            //如果遇到了空，则当前栈顶元素就是根节点
            tmp = s.top();
            s.pop();
            
        }
        
        return ans;
    }
};
