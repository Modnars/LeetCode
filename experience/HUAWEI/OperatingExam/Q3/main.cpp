#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

// 编辑距离(动态规划)
int edit_distance(const std::string &str1, const std::string &str2) {
    int len1 = str1.size(), len2 = str2.size();
    std::vector<std::vector<int>> matrix(len1+1, std::vector<int>(len2+1, 0));
    for (int i = 0; i <= len1; ++i)
        matrix[i][0] = i;
    for (int i = 0; i <= len2; ++i)
        matrix[i][0] = i;
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = std::min(matrix[i-1][j-1] + 1, 
                        std::min(matrix[i-1][j]+1, matrix[i][j-1]+1));
            }
        }
    }
    return matrix[len1][len2];
}

int main(int argc, const char *argv[]) {
    int N, ans = 0;
    std::cin >> N;
    std::vector<std::string> text1, text2;
    std::string line;
    for (int i = 0; i != N; ++i) {
        std::cin >> line;
        text1.push_back(line);
    }
    for (int i = 0; i != N; ++i) {
        std::cin >> line;
        text2.push_back(line);
    }
    for (int i = 0; i != N; ++i)
        ans += edit_distance(text1[i], text2[i]);
    std::cout << ans << std::endl;
    return EXIT_SUCCESS;
}
