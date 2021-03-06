// 你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。
// 你必须正好使用k块木板。
// 编写一个方法，生成跳水板所有可能的长度。
//
// 返回的长度需要从小到大排列。 
//
// 示例 1 
//
// 输入：
// shorter = 1
// longer = 2
// k = 3
// 输出： [3,4,5,6]
// 解释：
// 可以使用 3 次 shorter，得到结果 3；使用 2 次 shorter 和 1 次 longer，得到结果 4 。以此类推，得到最终结果。
//
// 提示： 
//
// 
// 0 < shorter <= longer 
// 0 <= k <= 100000 
// 
// Related Topics 递归 记忆化 
// 👍 76 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 2021.02.08 只有两块板，那么就先都选短板，然后逐个增加长板的数量即可，顺序不需要考虑，所以不需要回溯
    // 用脑思考，来执行每一步程序
    vector<int> divingBoard(int shorter, int longer, int k)
    {
        if (k == 0) return {};
        if(shorter == longer) return {shorter * k};
        vector<int> ret;
        for (int i = 0; i <= k; ++i)
        {
            ret.push_back(shorter * (k - i) + longer * i);
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
