/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (60.98%)	46	-
Tags
Companies
我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。

只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。

编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。

 

示例：

输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
输出：true
解释：我们翻转值为 1，3 以及 5 的三个节点。
Flipped Trees Diagram
 

提示：

每棵树最多有 100 个节点。
每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数。
 
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
    //思路：首先确定dfs的终止条件呢，如果两者根都为null，则返回true
    //若两者一个为空，一个不为空或者两者对应值不一样，则返回false
    //之后由于镜像，所以每一层要么是树1左对树2左，要么是树1左对树2右，要保证这两者子树都为真才是镜像二叉树
    //我之前想用中序遍历做没搞定，后来又用想到一样的思路但是代码没写出来，主要是因为画蛇添足的在递归前面
    //加了判断
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1==NULL||root2==NULL||root1->val!=root2->val)
            return false;
        return flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right)||
        flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left);
    }
};
