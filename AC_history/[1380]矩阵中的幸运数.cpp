//给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。 
//
// 幸运数是指矩阵中满足同时下列两个条件的元素： 
//
// 
// 在同一行的所有元素中最小 
// 在同一列的所有元素中最大 
// 
//
// 
//
// 示例 1： 
//
// 输入：matrix = [
// [3,7,8],
// [9,11,13],
// [15,16,17]
// ]
//输出：[15]
//解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 
//
// 示例 2： 
//
// 输入：matrix =
// [
// [1,10,4,2],
// [9,3,8,7],
// [15,16,17,12]
// ]
//输出：[12]
//解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 
//
// 示例 3： 
//
// 输入：matrix = [[7,8],[1,2]]
//输出：[7]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= n, m <= 50 
// 1 <= matrix[i][j] <= 10^5 
// 矩阵中的所有元素都是不同的 
// 
// Related Topics 数组 
// 👍 31 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 一刷，2021.01.01 寻找 鞍点
    // 1. 遍历所有行
    //    遍历当前行所有的元素，找到最小的元素 a，和对应列的位置 j
    //    判断 第 j 列 a 是否是最大值
    // Time: O(N^2)
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        for (int i = 0; i < matrix.size(); ++i)
        {
            int cur = matrix[i][0];
            int idx = 0;
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] < cur)
                {
                    cur = matrix[i][j];
                    idx = j;
                }
            }
            bool flag = true;
            for (int r = 0; r < matrix.size(); ++r)
            {
                if (matrix[r][idx] > cur)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(matrix[i][idx]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
