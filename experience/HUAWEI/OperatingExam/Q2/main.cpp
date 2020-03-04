#include <vector>
#include <cstdlib>
#include <iostream>

void backtrack(int depth, int remain, int k, std::vector<int> &path, 
        std::vector<std::vector<int>> &ans) {
    if (depth == k-1) { // 若递归到达叶子结点，记录完整路径，并添加
        path.push_back(remain); // 记录所剩个数
        ans.push_back(path);    // 添加可行解
        path.pop_back();        // 记录后进行回溯，返回上一状态
    } else {
        for (int i = remain; i >= 0; --i) {
            path.push_back(i);  // 添加当前层获得数目i的可能解
            backtrack(depth+1, remain-i, k, path, ans); // 递归
            path.pop_back();    // 回溯，返回上一状态
        }
    }
}

/**
 * 回溯(递归)求解
 */
int main(int argc, const char *argv[]) {
    int n, k;
    std::vector<int> path;
    std::vector<std::vector<int>> ans;
    std::cin >> n >> k;
    backtrack(0, n, k, path, ans);
    std::cout << ans.size() << std::endl;
    for (const auto &row : ans) {
        for (int i = 0; i != row.size(); ++i) {
            for (int j = 0; j != row[i]; ++j) 
                std::cout << "*";
            std::cout << ((i == row.size()-1) ? "" : "|");
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
