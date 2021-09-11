//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。 
//
// 不占用额外内存空间能否做到？ 
//
// 
//
// 示例 1: 
//
// 给定 matrix = 
//[
//  [1,2,3],   [7,8,9]
//  [4,5,6],   [4,5,6]
//  [7,8,9]    [1,2,3]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
// 
//
// 示例 2: 
//
// 给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//], 
//
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]
// 
// Related Topics 数组 
// 👍 137 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void reverse(vector<vector<int>> &matrix)
    {
        int half = matrix.size() / 2;
        for (int i = 0; i < half; ++i)
        {
            swap(matrix[i], matrix[matrix.size() - i - 1]);
        }
    }

    void rotate(vector<vector<int>>& matrix)
    {
        reverse(matrix);
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i)
        {
            for (int j = i + 1; j < col; ++j)
            {
                if (i == j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
