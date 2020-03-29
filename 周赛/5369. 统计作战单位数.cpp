/*

 n 名士兵站成一排。每个士兵都有一个 独一无二 的评分 rating 。

每 3 个士兵可以组成一个作战单位，分组规则如下：

从队伍中选出下标分别为 i、j、k 的 3 名士兵，他们的评分分别为 rating[i]、rating[j]、rating[k]
作战单位需满足： rating[i] < rating[j] < rating[k] 或者 rating[i] > rating[j] > rating[k] ，其中  0 <= i < j < k < n
请你返回按上述条件可以组建的作战单位数量。每个士兵都可以是多个作战单位的一部分。

 

示例 1：

输入：rating = [2,5,3,4,1]
输出：3
解释：我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
示例 2：

输入：rating = [2,1,3]
输出：0
解释：根据题目条件，我们无法组建作战单位。
示例 3：

输入：rating = [1,2,3,4]
输出：4
 

提示：

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
通过次数2,519提交次数3,081
*/
//思路：找到每个数组前面比他小的和比他大的两个数组记作dpmin和dpmax，然后根据这两个数组找个数。
//具体来看，只要当前数字比dpmin【j】大，说明有可能组成升序序列，只要判断dpmin【j】的个数大于1（前面数组比他小的个数大于1），就可以算作一个升序数组
//只要加上就好
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        vector<int>dpmin(len,0);
        vector<int>dpmax(len,0);
        int upans=0;
        int downans=0;//升序结果和降序结果
        for(int i=1;i<len;i++)
        {
            int cur=rating[i];
            for(int j=0;j<i;j++)
            {
                if(cur<rating[j])
                    dpmax[i]++;
                if(cur>rating[j])
                    dpmin[i]++;
            }
        }
        for(int i=2;i<len;i++)
        {
            int cur = rating[i];
            for(int j=1;j<i;j++)
            {
                if(cur>rating[j])
                {
                    if(dpmin[j]>0)
                        upans+=dpmin[j];
                }
                if(cur<rating[j])
                {
                    if(dpmax[j]>0)
                        downans+=dpmax[j];
                }
            }
        }
        cout<<downans<<" "<<upans;
        return downans+upans;
    }
};
