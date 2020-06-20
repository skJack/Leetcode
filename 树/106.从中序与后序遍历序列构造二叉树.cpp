/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (65.73%)	136	-
Tags
Companies
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/
class Solution {
public:
//不要忘记加&不然会超时
//和前面思路一样，注意明白为什么需要两个才能确定构成一棵树，我们需要后序/前序确定根的位置，之后根据中序确定左右子树的起止点位置，理解这一点就不会忘记。
    TreeNode* build(vector<int>& postorder,map<int,int>&m,int post_left,int post_right,int in_left,int in_right)
    {
        if(post_left>post_right||in_left>in_right)
            return NULL;
        else
        {
            TreeNode *root = new TreeNode(postorder[post_right]);
            int index = m[postorder[post_right]];

            //root->right = build(postorder,m,post_left+index-in_left,post_right-1,index+1,in_right);

            root->left = build(postorder,m,post_left,post_left+index-1-in_left,in_left,index-1);

            root->right = build(postorder,m,post_left+index-in_left,post_right-1,index+1,in_right);
            return root;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>m;
        int len = inorder.size();
        for(int i=0;i<len;i++)
        {
            m[inorder[i]] = i;
        }
        return build(postorder,m,0,len-1,0,len-1);
    }


    
};
