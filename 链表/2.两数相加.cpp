/*
两数相加
Category	Difficulty	Likes	Dislikes
algorithms	Medium (36.38%)	3861	-
Tags
Companies
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/
//注意头节点就好
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add=0;//表示进位
        ListNode *head = new ListNode(-1);
        ListNode *res = head;
        while(l1!=NULL&&l2!=NULL)
        {
            int l1val = l1->val;
            int l2val = l2->val;
            int ans = l1val+l2val+add;
            if(ans>9)
            {
                ans = ans%10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            ListNode *tmp = new ListNode(ans);
            res->next = tmp;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            int l1val = l1->val;
            int ans = l1val+add;
            if(ans>9)
            {
                ans = ans%10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            ListNode *tmp = new ListNode(ans);
            res->next = tmp;
            res = res->next;
            l1 = l1->next;
        }
        while(l2!=NULL)
        {
            int l2val = l2->val;
            int ans = l2val+add;
            if(ans>9)
            {
                ans = ans%10;
                add = 1;
            }
            else
            {
                add = 0;
            }
            ListNode *tmp = new ListNode(ans);
            res->next = tmp;
            res = res->next;
            l2 = l2->next;
        }
        if(add!=0)
        {
            ListNode *tmp = new ListNode(add);
            res->next = tmp;
        }
        //res = NULL;//删除尾节点
        return head->next;
    }
};
