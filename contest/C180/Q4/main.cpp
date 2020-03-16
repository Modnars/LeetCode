// URL    : https://leetcode-cn.com/contest/weekly-contest-180/problems/maximum-performance-of-a-team/
// Author : Modnar
// Date   : 2020/03/15
// Thanks : 前额叶没长好(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

using std::vector;

// Thanks: 前额叶没长好(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/balance-a-binary-search-tree/solution/di-gui-on-jie-fa-c-you-xian-dui-lie-by-time-limit/
// Time: 176ms(100.00%)  Memroy: 20.5MB(100.00%)
class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        for (int i = 0; i != n; ++i)
            data.emplace_back(Engineer(speed[i], efficiency[i]));
        std::sort(data.begin(), data.end());
        long long int sum = 0, ans = 0;
        for (int i = 0; i != n; ++i) {
            sum += data[i].s;
            pq.push(data[i].s);
            if (pq.size() > static_cast<std::size_t>(k)) {
                long long int tmp = pq.top();
                pq.pop();
                sum -= tmp;
            }
            ans = std::max(ans, sum*data[i].e);
        }
        return ans % 1000000007;
    }

private:
    struct Engineer {
        long long int s, e;
        Engineer(long long int _s, long long int _e) : s(_s), e(_e) { }
        bool operator<(const Engineer &r) const {
            return this->e > r.e;
        }
    };
    std::vector<Engineer> data;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    std::vector<int> speed = {2, 10, 3, 1, 5, 8}, efficiency = {5, 4, 3, 9, 7, 2};
    std::cout << (new Solution())->maxPerformance(6, speed, efficiency, 2) 
              << std::endl;
    // Ans: 60
    std::cout << (new Solution())->maxPerformance(6, speed, efficiency, 3) 
              << std::endl;
    // Ans: 68
    std::cout << (new Solution())->maxPerformance(6, speed, efficiency, 4) 
              << std::endl;
    // Ans: 72
    return EXIT_SUCCESS;
}
