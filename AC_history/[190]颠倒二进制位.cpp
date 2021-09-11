//颠倒给定的 32 位无符号整数的二进制位。 
//
//  res <<= 1;
//  res += n & 1;
//  n >>= 1;
// 示例 1： 
//
// 输入: 00000010100101000001111010011100
//输出: 00111001011110000010100101000000
//解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
//     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。 
//
// 示例 2： 
//
// 输入：11111111111111111111111111111101
//输出：10111111111111111111111111111111
//解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
//     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。 
//
// 
//
// 提示： 
//
// 
// 请注意，在某些语言（如 Java）中，没有无符号整数类型。
// 在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的
//还是无符号的，其内部的二进制表示形式都是相同的。 
// 在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -10737418
//25。 
// 
//
// 
//
// 进阶: 
//如果多次调用这个函数，你将如何优化你的算法？ 
// Related Topics 位运算 
// 👍 203 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 答案
    // 和 反转数字 123 的思路一模一样
    // ans = ans * 10
    // ans += n % 10;
    // n /= 10;
    uint32_t reverseBits(uint32_t n)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            // 对称的
            // ans 左移
            ans <<= 1;
            // ans 加上当前的结果
            ans += (n & 1);
            // n 右移动
            n >>= 1;
        }

    }

    // 二刷 2020.12.30
    // 第二次刷 感觉自己的思路不太对，我的想法是找到最高位的 1，然后不断的 >>
    // 遍历与 n 的关系，把对应高位置的值添加到相应的低位上
    // 没想到我这个办法更厉害，最高位就是 INT_MAX + 1
    //	Success:
    //  Runtime:0 ms, faster than 100.00% of C++ online submissions.
    //	Memory Usage:6.1 MB, less than 69.03% of C++ online submissions.
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        uint32_t cur = static_cast<uint32_t >(INT_MAX) + 1;
        for (int i = 0; i < 32; ++i)
        {
            if ((n & cur) != 0)
            {
                ans += (1 << i);
            }
            cur >>= 1;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
