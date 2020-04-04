/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (42.97%)	51	-
Tags
Companies
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。

给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。

 

示例 1：

输入：A = [1,2,0,0], K = 34
输出：[1,2,3,4]
解释：1200 + 34 = 1234
示例 2：

输入：A = [2,7,4], K = 181
输出：[4,5,5]
解释：274 + 181 = 455
示例 3：

输入：A = [2,1,5], K = 806
输出：[1,0,2,1]
解释：215 + 806 = 1021
示例 4：

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
输出：[1,0,0,0,0,0,0,0,0,0,0]
解释：9999999999 + 1 = 10000000000
 

提示：

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
如果 A.length > 1，那么 A[0] != 0
*/
class Solution {
public:
    vector<int> addToArrayForm1(vector<int>& A, int K) {
        int len = A.size();
        int index = len-1;
        vector<int>ans;
        int add = 0;
        while (index>=0||K!=0)
        {
            int tmp = K%10;
            K = K/10;
            int tmp_result = tmp+A[index]+add;
            if(tmp_result>=10)
                add = 1;
            else
                add = 0;
            ans.push_back(tmp_result%10);
            index--;
        }
        for(int i=index;i>=0;i--)
        {
            ans.push_back(A[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    //方法二：用数组中的数直接加到k中，然后逐位取模。非常非常聪明
    //思路：将A的从低位（尾部数字）与K相加，同时K每次都要丢弃个位数字，然后与A的下一个数字相加
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        int lastNum=K,i=A.size()-1;
        while(i>=0||lastNum>0)
        {   
            //对应位相加
            if(i>=0)
                lastNum+=A[i--];
            //尾部数字添加到result中，同时k需要丢弃尾部数字
            result.push_back(lastNum%10);
            lastNum/=10;
        }
        //注意：要反转，因为低位数字都排在数组的前面了，所以需要反转
        reverse(result.begin(),result.end());
        return result;
    }

};
