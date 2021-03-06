// 给你一个由大小写英文字母组成的字符串 s 。
//
// 一个整理好的字符串中，两个相邻字符 s[i] 和 s[i+1]，其中 0<= i <= s.length-2 ，要满足如下条件: 
//
// 
// 若 s[i] 是小写字符，则 s[i+1] 不可以是相同的大写字符。 
// 若 s[i] 是大写字符，则 s[i+1] 不可以是相同的小写字符。 
// 
//
// 请你将字符串整理好，每次你都可以从字符串中选出满足上述条件的 两个相邻 字符并删除，直到字符串整理好为止。 
//
// 请返回整理好的 字符串 。题目保证在给出的约束条件下，测试样例对应的答案是唯一的。 
//
// 注意：空字符串也属于整理好的字符串，尽管其中没有任何字符。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "leEeetcode"
//输出："leetcode"
//解释：无论你第一次选的是 i = 1 还是 i = 2，都会使 "leEeetcode" 缩减为 "leetcode" 。
// 
//
// 示例 2： 
//
// 
//输入：s = "abBAcC"
//输出：""
//解释：存在多种不同情况，但所有的情况都会导致相同的结果。例如：
//"abBAcC" --> "aAcC" --> "cC" --> ""
//"abBAcC" --> "abBA" --> "aA" --> ""
// 
//
// 示例 3： 
//
// 
//输入：s = "s"
//输出："s"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 100 
// s 只包含小写和大写英文字母 
// 
// Related Topics 栈 字符串 
// 👍 17 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷，2021.01.06， 这个题目典型的栈思想
    // 什么时候使用栈思想？ 相邻元素比较并消除的时候，比如有效的括号、这道题
    // 如果不用栈的话，可能会比较麻烦，可以用 string 当做栈，因为string 的 back 和 pop_back 的复杂度都是 1
    // 这道题提交了 4 次才过，原因是 初始 的字符的选择 # * - 都不可以，最终使用 ^ 通过了
    // Complexity:
    // Time: O(N)
    // Space: O(N)
    string makeGood1(string s)
    {
        stack<char> sta;
        sta.push('^');
        for (int i = 0; i < s.size(); ++i)
        {
            if (sta.top() - 32 == s[i] || sta.top() + 32 == s[i])
            {
                sta.pop();
            } else
            {
                sta.push(s[i]);
            }
        }
        string ret = "";
        while (sta.size() > 1)
        {
            ret = sta.top() + ret;
            sta.pop();
        }
        return ret;
    }

    // 二刷 2021.01.07 栈思想
    // 无论多简单的题，看看题解，你总会有收获
    string makeGood(string s)
    {
        if (s.empty()) return "";
        string ret;
        ret.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
            if (ret.back() - 32 == s[i] || ret.back() + 32 == s[i])
            {
                ret.pop_back();
            } else
            {
                ret.push_back(s[i]);
            }
        }
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
