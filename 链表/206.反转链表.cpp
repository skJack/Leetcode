/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (66.38%)	959	-
Tags
Companies
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

class Solution {
public:
    //思路：遍历节点的时候把当前节点的next改成上一个即可
    //注意最后返回prev
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        
    }
};
