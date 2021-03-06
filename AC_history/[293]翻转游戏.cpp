//你和朋友玩一个叫做「翻转游戏」的游戏，游戏规则：给定一个只有 + 和 - 的字符串。你和朋友轮流将 连续 的两个 "++" 反转成 "--"。 当一方无法进
//行有效的翻转时便意味着游戏结束，则另一方获胜。 
//
// 请你写出一个函数，来计算出第一次翻转后，字符串所有的可能状态。 
//
// 
//
// 示例： 
//
// 输入: s = "++++"
//输出: 
//[
//  "--++",
//  "+--+",
//  "++--"
//]
// 
//
// 注意：如果不存在可能的有效操作，请返回一个空列表 []。 
// Related Topics 字符串 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector <string> generatePossibleNextMoves(string s)
    {
        vector <string> ans;
        if (s.size() < 2) return ans;
        int start = 0;
        while (start < s.size() - 1)
        {
            if (s[start] == '+' && s[start + 1] == '+')
            {
                string tmp = s;
                tmp[start] = '-';
                tmp[start + 1] = '-';
                ans.push_back(tmp);
            }
            start ++;

        }
        return ans;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
