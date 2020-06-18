/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (63.15%)	294	-
Tags
Companies
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

// @lc code=start
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
    //这种题记住套路。
    //就是递归的通过寻找左右子树的边界确定做子树和右子树的范围，脑子里一定要先画图
    TreeNode* build(vector<int>& preorder,map<int,int>&m,int left_pre,int right_pre,int left_in,int right_in)
    {
        if(left_pre>right_pre||left_in>right_in)
        {
            //区间不存在
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[left_pre]);
        int preindex = m[preorder[left_pre]];

        root->left = build(preorder,m,left_pre+1,preindex-left_in+left_pre,left_in,preindex-1);

        root->right = build(preorder,m,preindex-left_in+left_pre+1,right_pre,preindex+1,right_in);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len_pre = preorder.size();
        int len_in = inorder.size();
        map<int,int>m;//用一个哈希表找到中序遍历的位置，方便寻找中序遍历中根节点的位置
        for(int i=0;i<len_in;i++)
        {
            m[inorder[i]] = i;
        }
        return build(preorder,m,0,len_pre-1,0,len_in-1);

    }
};
