//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
//
// 说明： 
//
// 
// 所有数字都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
// 
//
// 示例 2: 
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
// 
// Related Topics 数组 回溯算法 
// 👍 228 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    vector <vector<int>> ans;

    void backtrack(int n, int k, int start, int depth, int cur, vector<int> path)
    {
        if (depth == k)
        {
            if (cur == n)
            {
                ans.push_back(path);
                return;
            }
        }
        for (int i = start; i < 10; ++i)
        {
            if (cur > n || depth > k) return;
            cur += i;
            path.push_back(i);
            backtrack(n, k, i + 1, depth + 1, cur, path);
            path.pop_back();
            cur -= i;
        }

    }

    vector <vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path;
        backtrack(n, k, 1, 0, 0, path);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
