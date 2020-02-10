/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (45.59%)	443	-
Tags
Companies
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
//做法：使用一个大小为numEows的数组即可，要清楚z字变换的真正含义就是正反交替的放入结果数组中，注意答案中flag的运用
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<2)
        {
            return s;
        }
            
        string ans = "";
        vector<string>arr(numRows+1,"");
        int len = s.size();
        int flag = -1;//索引增量，每次到转折点就求反
        int index = 0;
        for(int i=0;i<len;i++)//从1开始，为了避免混淆
        {
            arr[index].push_back(s[i]);
            if(index==0||index==numRows-1)
                {
                    if(flag==1)
                        flag = -1;
                    else if(flag==-1)
                        flag = 1;
                }
            index += flag;
        }
        for(int i=0;i<numRows;i++)
        {
            ans+=arr[i];
        }
        return ans;
    }
};
