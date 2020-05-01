/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (54.21%)	449	-
Tags
Companies
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
我们可以如下递归地定义两个链表里的 merge 操作（忽略边界情况，比如空链表等）：

\left\{ \begin{array}{ll} list1[0] + merge(list1[1:], list2) & list1[0] < list2[0] \\ list2[0] + merge(list1, list2[1:]) & otherwise \end{array} \right.
{ 
list1[0]+merge(list1[1:],list2)
list2[0]+merge(list1,list2[1:])
​	
  
list1[0]<list2[0]
otherwise
​	
 

也就是说，两个链表头部值较小的一个节点与剩下元素的 merge 操作结果合并。

*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val<l2->val)
        {
            //意思是保留当前l1的val值，后面的进行再合并
            l1->next =  mergeTwoLists(l1->next,l2);
            return l1;
        }
        else
        {
            //同理
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
