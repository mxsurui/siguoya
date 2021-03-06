//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 
//
// 
//
// 说明: 
//
// 
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。 
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。 
// 
//
// 
//
// 示例: 
//
// 输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6] 
// Related Topics 数组 双指针 
// 👍 598 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int cur = nums1.size() - 1;
        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] > nums2[p2])
            {
                nums1[cur] = nums1[p1];
                p1--;
            } else
            {
                nums1[cur] = nums2[p2];
                p2--;
            }
            cur--;
        }
        while(p1 >= 0)
        {
            nums1[cur] = nums1[p1];
            cur --;
            p1 --;
        }
        while(p2 >= 0)
        {
            nums1[cur] = nums2[p2];
            cur --;
            p2 --;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
