/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (61.74%)	230	-
Tags
Companies
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
//思路：根据区间减即可，特殊字符特殊处理
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int tmp = num;
        string ans = "";
        while(tmp>0)
        {
            if(tmp>0&&tmp<5)
            {
                if(tmp<4)
                {
                    tmp = tmp-1;
                    ans+='I';
                }
                else
                {
                
                    tmp = tmp-4;
                    ans+="IV";
                }
            }
            if(tmp>=5&&tmp<10)
            {
                if(tmp<9)
                {
                    tmp = tmp-5;
                    ans+='V';
                }
                else
                {
                    tmp = tmp-9;
                    ans+="IX";
                }
            }
            if(tmp>=10&&tmp<50)
            {
                if(tmp<40)
                {
                    tmp = tmp-10;
                    ans+='X';
                }
                else
                {
                    tmp = tmp-40;
                    ans+="XL";
                }
            }
            if(tmp>=50&&tmp<100)
            {
                if(tmp<90)
                {
                    tmp = tmp-50;
                    ans+='L';
                }
                else
                {
                    tmp = tmp-90;
                    ans+="XC";
                }
            }
            if(tmp>=100&&tmp<500)
            {
                if(tmp<400)
                {
                    tmp = tmp-100;
                    ans+='C';
                }
                else
                {
                    tmp = tmp-400;
                    ans+="CD";
                }
            }
            if(tmp>=500&&tmp<1000)
            {
                if(tmp<900)
                {
                    tmp = tmp-500;
                    ans+='D';
                }
                else
                {
                    tmp = tmp-900;
                    ans+="CM";
                }
            }
            if(tmp>=1000)
            {
                tmp = tmp-1000;
                ans+='M';
            }

        }
        return ans;
    }
};
    //class Solution:
    // def intToRoman(self, num: int) -> str:
    //     # 使用哈希表，按照从大到小顺序排列
    //     hashmap = {1000:'M', 900:'CM', 500:'D', 400:'CD', 100:'C', 90:'XC', 50:'L', 40:'XL', 10:'X', 9:'IX', 5:'V', 4:'IV', 1:'I'}
    //     res = ''
    //     for key in hashmap:
    //         if num // key != 0:
    //             count = num // key  # 比如输入4000，count 为 4
    //             res += hashmap[key] * count 
    //             num %= key
    //     return res

