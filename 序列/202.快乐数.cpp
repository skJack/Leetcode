/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (56.59%)	231	-
Tags
Companies
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

// @lc code=start
class Solution {
public:
    int happy(int n)
    {
        int ans = 0;
        while(n!=0)
        {
            int tmp = n%10;
            ans+=tmp*tmp;
            n = n/10;
        }
        return ans;
    }
    //方法一：暴力
    bool isHappy1(int n) {
        int num = n;
        set<int>s;
        s.insert(n);
        while (1)
        {
            num = happy(num);
            if(num==1)
                return true;
            if(s.find(num)!=s.end())
                return false;
            s.insert(num);
        }
        return false;
    }
    //方法二：快慢指针法
    //类似链表有无环的做法
    bool isHappy(int n) {
        int slow=n,fast=n;
        do{
            slow = happy(slow);
            fast = happy(fast);
            fast = happy(fast);
        }
        while(slow!=fast);
        if(slow==1)
            return true;
        else
        {
            return false;
        }
        

    }
};
