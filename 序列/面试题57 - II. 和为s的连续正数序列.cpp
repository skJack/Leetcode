/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5
 

通过次数6,053提交次数8,494

*/
class Solution {
public:
    int sum(int head,int tail)
    {
        return ((head+tail)*(tail-head+1))/2;
    }
    vector<int> squence(int head,int tail)
    {
        vector<int> ans;
        for(int i=head;i<=tail;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
    //方法一：暴力搜索
    vector<vector<int>> findContinuousSequence1(int target) {
        vector<vector<int>> ans;
        for(int i=1;i<=target/2;i++)
        {
            int j=i+1;
            while(sum(i,j)<=target)
            {
                if(sum(i,j)==target)
                    {
                        ans.push_back(squence(i,j));
                        break;
                    }
                else
                    j++;
            }
        }
        return ans;
    }
    //方法二：滑动窗口
    vector<vector<int>> findContinuousSequence(int target) {
    int i = 1; // 滑动窗口的左边界
    int j = 1; // 滑动窗口的右边界
    int sum = 0; // 滑动窗口中数字的和
    vector<vector<int>> res;
    while(i<=target/2)
    {
        if(sum>target)
        {
            //窗口数字和太大了
            sum-=i;
            i++;
        }
        else if(sum<target)
        {
            //窗口数字和太小了，右边界右移
            sum+=j;
            j++;
        }
        else if(sum==target)
        {
            vector<int>tmp;
            for(int k=i;k<=j-1;k++)
            {
                tmp.push_back(k);
            }
            res.push_back(tmp);
            sum-=i;
            i++;
        }
    }
    return res;
}
};
