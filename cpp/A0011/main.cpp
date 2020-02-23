// URL    : https://leetcode-cn.com/problems/container-with-most-water/
// Author : Modnar
// Date   : 2020/02/23

#include <bits/stdc++.h>

/* ************************* */

/**
 * 暴力法
 */
// Complexity: O(n^2)
// Time: 1820ms  Memory: 16MB
class Solution {
public:
    int maxArea(std::vector<int> &height) {
        if (height.size() <= 1) return 0;
        int ans = 0;
        auto len = height.size();
        for (int i = 0; i != len; ++i)
            for (int j = i+1; j != len; ++j) {
                int area = std::min(height[i], height[j]) * (j - i);
                ans = area > ans ? area : ans;
            }
        return ans;
    }
};

/* ************************* */

/**
 * 双指针法:
 *     最初我们考虑由最外围两条线段构成的区域。现在，为了使面积最大化，我们需要考虑
 * 更长的两条线段之间的区域。如果我们试图将指向较长线段的指针向内侧移动，矩形区域的
 * 面积将受限于较短的线段而不会获得任何增加。但是，在同样的条件下，移动指向较短线段
 * 的指针尽管造成了矩形宽度的减小，但却可能会有助于面积的增大。因为移动较短线段的指
 * 针会得到一条相对较长的线段，这可以克服由宽度减小而引起的面积减小。
 */
namespace AnsOne {
    // Thanks: Official(@leetcode.cn)
    // Complexity: Time: O(n)  Space: O(1)
    // Time: 24ms  Memory: 16MB
    class Solution {
    public:
        int maxArea(std::vector<int> &height) {
            if (height.size() <= 1) return 0;
            int ans = 0, i = 0, j = height.size()-1;
            while (i < j) {
                int hl = height[i], hr = height[j];
                if (hl < hr) {
                    ans = hl*(j-i) > ans ? hl*(j-i) : ans;
                    ++i;
                } else {
                    ans = hr*(j-i) > ans ? hr*(j-i) : ans;
                    --j;
                }
            }
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsOne::Solution;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << (new Solution())->maxArea(height) << std::endl;
    // Ans: 49
    return EXIT_SUCCESS;
}
