// URL    : 
// Author : Modnar
// Date   : 2020/03/18

#include <bits/stdc++.h>

/* ************************* */

class Solution {
public:
    bool isRectangleOverlap(std::vector<int> &rec1, std::vector<int> &rec2) {
        double a1 = rec1[2] - rec1[0], b1 = rec1[3] - rec1[1];
        // std::cout << "a1:" << a1 << ", b1:" << b1 << std::endl;
        double a2 = rec2[2] - rec2[0], b2 = rec2[3] - rec2[1];
        // std::cout << "a2:" << a2 << ", b2:" << b2 << std::endl;
        double px = (rec1[0] + rec1[2]) / 2.0, py = (rec1[1] + rec1[3]) / 2.0;
        // std::cout << "(" << px << ", " << py << ")" << std::endl;
        double qx = (rec2[0] + rec2[2]) / 2.0, qy = (rec2[1] + rec2[3]) / 2.0;
        // std::cout << "(" << qx << ", " << qy << ")" << std::endl;
        return (std::abs(px-qx) < (a1+a2)/2.0 && std::abs(py-qy) < (b1+b2)/2.0);
    }
};

/* ************************* */

/**
 * 针对上述表达式的数学转换
 */
// Time: 0ms(100.00%)  Memory: 9.2MB(6.86%)
namespace AnsOne {
    class Solution {
    public:
        bool isRectangleOverlap(std::vector<int> &rec1, std::vector<int> &rec2) {
            return (std::abs(double(rec1[0])-rec2[0]+rec1[2]-rec2[2]) < 
                    double(rec1[2])-rec1[0]+rec2[2]-rec2[0]) &&
                (std::abs(double(rec1[1])-rec2[1]+rec1[3]-rec2[3]) < 
                 double(rec1[3])-rec1[1]+rec2[3]-rec2[1]);
        }
    };
}

int main(int argc, const char *argv[]) {
    std::vector<int> rec1 = {0, 0, 2, 2}, rec2 = {1, 1, 3, 3};
    std::cout << (new Solution())->isRectangleOverlap(rec1, rec2) << std::endl;
    // Ans: 1 (true)
    rec1 = {0, 0, 1, 1}, rec2 = {1, 0, 2, 1};
    std::cout << (new Solution())->isRectangleOverlap(rec1, rec2) << std::endl;
    // Ans: 0 (false)
    return EXIT_SUCCESS;
}
