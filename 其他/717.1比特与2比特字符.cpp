/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (46.09%)	116	-
Tags
Companies
有两种特殊字符。第一种字符可以用一比特0来表示。第二种字符可以用两比特(10 或 11)来表示。

现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。

示例 1:

输入: 
bits = [1, 0, 0]
输出: True
解释: 
唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
示例 2:

输入: 
bits = [1, 1, 1, 0]
输出: False
解释: 
唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
注意:

1 <= len(bits) <= 1000.
bits[i] 总是0 或 1.

*/

// @lc code=start
class Solution {
public:
    //想法：要找没有的，没有提供单独的1和01编码，就从这里突破
    //思路：首先分析问题，可以看出和末尾0后面紧跟的1的个数有关系
    //当1的个数为偶数时，一定可以编队成一个比特，因为没有单独的1或者01这个编码方法，
    //所以偶数个1必定两两成对，不然有一个就落单了。
    //当为奇数个时，正好前面的可以组成11，最后一个和0组成01，所以返回false
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int count = 0;
        for(int i = len-2;i>=0;i--)
        {
            if(bits[i]==1)
                count++;
            else
                break;
        }
        if(count%2==0)
            return true;
        else
            return false;
    }
};
