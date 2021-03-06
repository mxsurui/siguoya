//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 
//
// 示例 1: 
//
// 输入: 121
//输出: true
// 
//
// 示例 2: 
//
// 输入: -121
//输出: false
//解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3: 
//
// 输入: 10
//输出: false
//解释: 从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 进阶: 
//
// 你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学 
// 👍 1365 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 利用字符串翻转来判断
    bool isPalindrome1(int x)
    {
        if (x < 0) return false;
        string s = to_string(x);
        string sr = s;
        reverse(sr.begin(), sr.end());
        return s == sr;
    }

    // 利用双指针来判断
    bool isPalindrome2(int x)
    {
        if (x < 0) return false;
        string s = to_string(x);
        int l = 0, r = s.size() - 1;
        while(l < r)
        {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    // 利用递归来判断
    int left = 0;
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        string s = to_string(x);
        return dfs(s, 0);
    }

    bool dfs(string &s, int idx)
    {
        if (idx == s.size()) return true;
        bool flag = dfs(s, idx + 1);
        flag &= (s[left] == s[idx]);
        left ++;
        return flag;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
