/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (48.48%)	486	-
Tags
Companies
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //学会两个链表合并的递归写法
    ListNode* mergeTwo(ListNode* first,ListNode* second)
    {
        if(first==NULL)
            return second;
        if(second==NULL)
            return first;
        if(first->val<=second->val)
        {
            first->next = mergeTwo(first->next,second);
            return first;
        }
        else
        {
            second->next = mergeTwo(first,second->next);
            return second;
        }
        
        
    }
    //方法一：两两合并O（kn）
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        int len = lists.size();
        
        if(len==0)
            return NULL;
        ListNode* ans = lists[0];
        
        for(int i=1;i<len;i++)
        {
            ans = mergeTwo(ans,lists[i]);
        }
        return ans;
    }
    ListNode *merage(vector<ListNode*>& lists, int start, int end)
    {
        if(start==end)
            return lists[start];
        int mid = start + (end-start)/2;
        
        //int mid = (end+start)/2;
        cout<<mid<<endl;
        ListNode* l1 = merage(lists,start,mid);
        ListNode* l2 = merage(lists,mid+1,end);
        return mergeTwo(l1,l2);

    }
    //方法二：分之合并 O(logk * n)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if(len==0)
            return NULL;
        return merage(lists,0,len-1);
    }


};
