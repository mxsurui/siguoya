// 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
//
// 一个字符串的 子序列 是指这样一个新的字符串：
// 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
// 
//
// 若这两个字符串没有公共子序列，则返回 0。 
//
// 
//
// 示例 1: 
//
// 输入：text1 = "abcde", text2 = "ace" 
//输出：3  
//解释：最长公共子序列是 "ace"，它的长度为 3。
// 
//
// 示例 2: 
//
// 输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc"，它的长度为 3。
// 
//
// 示例 3: 
//
// 输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= text1.length <= 1000 
// 1 <= text2.length <= 1000 
// 输入的字符串只含有小写英文字符。 
// 
// Related Topics 动态规划 
// 👍 302 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 字符串问题转为 二维 dp table
    // dp[i][j] 表示 text1的第 i 个字符之前的子字符串和 text2 的第 j 个字符之前的子串的最长公共子序列的个数
    // 比如 "" 和 任意字符串的公共子序列个数为0
    // "a" 和 "abcbd" 的最长公共子序列长度为 1
    // "ad" 和 "abcbd" 的最长公共子序列长度为 2
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size() + 1;
        int n2 = text2.size() + 1;
        vector <vector<int>> dp(n1, vector<int>(n2, 0));
        for (int i = 1; i < n1; ++i)
        {
            for (int j = 1; j < n2; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
