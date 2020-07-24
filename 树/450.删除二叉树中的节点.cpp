/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (37.19%)	149	-
Tags
Companies
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
*/

class Solution {
public:
    TreeNode*target = NULL;
    TreeNode*leaf = NULL;
    //方法一：未调通。思想是先找到，然后把目标节点的左子树接到目标节点最左边。但这样太麻烦了.其实思想一样
    void find(TreeNode* root,int key,TreeNode* father)
    {
        if(root==NULL)
            return;
        if(key == root->val)
        {
            target = root;
            return;
        }
        if(key>root->val)
            find(root->right,key,root);
        if(key<root->val)
            find(root->left,key,root);
    } 
    void dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            leaf = root;
            return;
        }
        if(!root->left&&!root->right)
            {
                leaf = root;
                return;
            }
        dfs(root->left);
    }
    TreeNode* deleteNode1(TreeNode* root, int key) {
        TreeNode* father = root;
        find(root,key,father);//寻找目标节点和他爸爸
        if(target == NULL)
            return root;
        dfs(target->right);//找右节点的左几点的叶子结点,存在leaf中
        if(leaf==NULL)
            target->right = target->left;
        else
            leaf->left = target->left;
        //cout<<leaf->val<<" "<<target->val<<" "<<father->val<<endl;
        if(father->left!=NULL&&father->left->val==key)
        {
            father->left = target->right;
        }
        else
        {
            father->right = target->right;
        }
        delete target;
        return root;
    }
    //方法二：前面一样
    /*
    首先明确二叉搜索树“左小右大”的特性，即任意一个节点的值小于等于它的右子树中所有节点的值，大于等于它的左子树中所有节点的值。
 另当前节点为Cur_Node。
 若Cur_Node.val=key，那么就定位到了要删除的节点所在位置。
 接着考虑Cur_Node的具体情况。
     如果Cur_Node左孩子为空，那么用它的右孩子来顶替它的位置。
     如果如果Cur_Node右孩子为空，那么用它的左孩子来顶替它的位置。
     如果Cur_Node既有左孩子又有右孩子。
     那么可以用左子树中有最大值的节点（假设叫MaxNode）来顶替Cur_Node的位置，
     或者用右子树中有最小值的节点（假设叫MinNode）来顶替Cur_Node的位置。
     然后在左子树中删除MaxNode，或者在右子树中删除MinNode。
 若Cur_Node.val > key，则进入到Cur_Node的左子树中去寻找要删除的节点。
 若Cur_Node.val < key，则进入到Cur_Node的右子树中去寻找要删除的节点。
但是也有点蠢，是直接用递归替换法
    */
   TreeNode* deleteNode(TreeNode *root, int key) {
        if (root == NULL) return NULL;

        if (root->val == key) {
            if(root->left == NULL) return root->right;  //当前节点没有左孩子，右孩子顶替
            if(root->right == NULL) return root->left;    // 当前节点没有右孩子，左孩子顶替

            // 当前节点有左右孩子，从左子树中选择有最大值的节点顶替当前节点, 或者从右子树中找到有最小值的节点来顶替
            TreeNode *MaxNode = getMaxNode(root->left);
            root->val = MaxNode->val;
            //删除MinNode节点之后得到新的左子树
            root->left = deleteNode(root->left, MaxNode->val);

        }else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode *getMaxNode(TreeNode *root){
        while(root->right != NULL) root = root->right;
        return root;
    }
};
