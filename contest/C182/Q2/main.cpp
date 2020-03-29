// URL    : https://leetcode-cn.com/contest/weekly-contest-182/problems/count-number-of-teams/
// Author : Modnar
// Date   : 2020/03/29

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    int numTeams(std::vector<int> &rating) {
        std::vector<int> path;
        int ans = 0;
        backtrack(ans, 0, 0, 3, rating, path);
        backtrack1(ans, 0, 0, 3, rating, path);
        return ans;
    }

private:
    void backtrack(int &ans, int s, int depth, int lim, std::vector<int> &nums, std::vector<int> &path) {
        if (depth == lim) {
            ++ans;
            return;
        }
        for (int i = s; i < nums.size(); ++i) {
            if (path.empty() || path.back() < nums[i]) {
                path.emplace_back(nums[i]);
                backtrack(ans, i+1, depth+1, lim, nums, path);
                path.pop_back();
            }
        }
    }

    void backtrack1(int &ans, int s, int depth, int lim, std::vector<int> &nums, std::vector<int> &path) {
        if (depth == lim) {
            ++ans;
            return;
        }
        for (int i = s; i < nums.size(); ++i) {
            if (path.empty() || path.back() > nums[i]) {
                path.emplace_back(nums[i]);
                backtrack1(ans, i+1, depth+1, lim, nums, path);
                path.pop_back();
            }
        }
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> rating = {2, 5, 3, 4, 1};
    std::cout << (new Solution())->numTeams(rating) << std::endl;
    // Ans: 3
    rating = {2, 1, 3};
    std::cout << (new Solution())->numTeams(rating) << std::endl;
    // Ans: 0
    rating = {1, 2, 3, 4};
    std::cout << (new Solution())->numTeams(rating) << std::endl;
    // Ans: 4
    return EXIT_SUCCESS;
}
