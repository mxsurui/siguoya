//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉搜索树: root = [6,2,8,0,4,7,9,null,null,3,5] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
//输出: 6 
//解释: 节点 2 和节点 8 的最近公共祖先是 6。
// 
//
// 示例 2: 
//
// 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
//输出: 2
//解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉搜索树中。 
// 
// Related Topics 树 
// 👍 374 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:

    bool isInTheTree(TreeNode *root, TreeNode *aim)
    {
        if (!root) return false;
        if (root == aim) return true;
        bool l = isInTheTree(root->left, aim);
        bool r = isInTheTree(root->right, aim);
        return l || r;
    }


    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return NULL;
        if (root == p || root == q) return root;  // 如何root与其中一个相等，那么他必是祖先
        bool lp, lq, rp, rq;
        lp = isInTheTree(root->left, p);
        rp = !lp;
        rq = isInTheTree(root->right, q);
        lq = !rq;
        if (lp && rq || rp && lq) return root;
        if (lp && lq) return lowestCommonAncestor(root->left, p, q);
        if (rp && rq) return lowestCommonAncestor(root->right, p, q);
        return NULL;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
