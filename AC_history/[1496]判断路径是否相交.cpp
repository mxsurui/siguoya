// 给你一个字符串 path，其中 path[i] 的值可以是 'N'、'S'、'E' 或者 'W'，分别表示向北、向南、向东、向西移动一个单位。
//
// 机器人从二维平面上的原点 (0, 0) 处开始出发，按 path 所指示的路径行走。 
//
// 如果路径在任何位置上出现相交的情况，也就是走到之前已经走过的位置，请返回 True ；否则，返回 False 。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：path = "NES"
//输出：false 
//解释：该路径没有在任何位置相交。 
//
// 示例 2： 
//
// 
//
// 输入：path = "NESWW"
//输出：true
//解释：该路径经过原点两次。 
//
// 
//
// 提示： 
//
// 
// 1 <= path.length <= 10^4 
// path 仅由 {'N', 'S', 'E', 'W} 中的字符组成 
// 
// Related Topics 字符串 
// 👍 19 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 注意 unordered_set 无法哈希vector, pair
    bool isPathCrossing(string path)
    {
        vector<int> startPoint = {0, 0};
//        unordered_set<vector<int>> checker;   // 错误的方式
        set<vector<int>> checker;
        checker.insert(startPoint);
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == 'N') startPoint[0] += 1;
            else if (path[i] == 'S') startPoint[0] -= 1;
            else if (path[i] == 'E') startPoint[1] += 1;
            else startPoint[1] -= 1;
            if (checker.count(startPoint)) return true;
            checker.insert(startPoint);
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
