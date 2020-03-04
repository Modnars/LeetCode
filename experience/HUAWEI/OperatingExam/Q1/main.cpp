#include <vector>
#include <cstdlib>
#include <iostream>

/**
 * 控制输出
 *     只需实现N阶方阵顺时针旋转M个九十度并输出即可。
 */
int main(int argc, const char *argv[]) {
    int N, M;
    std::cin >> N;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
    for (int i = 0; i != N; ++i)
        for (int j = 0; j != N; ++j)
            std::cin >> matrix[i][j];
    std::cin >> M;
    M %= 4; // 顺时针旋转4个九十度即为一圈，故周期为4，模4即可
    if (M == 0) {           // 不发生旋转(或正好旋转了M/4圈)
        for (int i = 0; i != N; ++i) {
            for (int j = 0; j != N; ++j)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    } else if (M == 1) {    // 顺时针旋转90度
        for (int j = 0; j != N; ++j) {
            for (int i = N-1; i != -1; --i)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    } else if (M == 2) {    // 顺时针旋转180度
        for (int i = N-1; i != -1; --i) {
            for (int j = N-1; j != -1; --j)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    } else {                // 顺时针旋转270度
        for (int j = N-1; j != -1; --j) {
            for (int i = 0; i != N; ++i)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }
    return EXIT_SUCCESS;
}
