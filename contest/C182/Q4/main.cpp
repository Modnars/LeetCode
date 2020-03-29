// URL    : https://leetcode-cn.com/contest/weekly-contest-182/problems/find-all-good-strings/
// Author : Modnar
// Date   : 2020/03/29
// Thanks : zqy1018(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

const int M = 1000000007;

class Solution {
    int nxt[55];
    int f[505][55][2];
    int fd[55][27];
    int subp(int n, string &s, string &e){
        memset(f, 0, sizeof(f));
        int l = e.length();
        f[0][0][1] = 1;
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < 26; ++j){
                for (int t = 0; t < l; ++t){
                    f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][0]) % M;
                    if (j < s[i - 1] - 'a')
                        f[i][fd[t][j]][0] = (f[i][fd[t][j]][0] + f[i - 1][t][1]) % M;
                    else if (j == s[i - 1] - 'a')
                        f[i][fd[t][j]][1] = (f[i][fd[t][j]][1] + f[i - 1][t][1]) % M;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < l; ++j){
            res = (res + f[n][j][0]) % M;
            res = (res + f[n][j][1]) % M;
        }
        return res;
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        nxt[0] = -1;
        int l = evil.size();
        // 构造 next 数组
        for (int j = -1, i = 1; i < l; ++i){
            while (j > -1 && evil[i] != evil[j + 1])
                j = nxt[j];
            if (evil[i] == evil[j + 1])
                nxt[i] = ++j;
            else nxt[i] = -1;
        }
        // 计算失配转移
        for (int i = -1; i < l - 1; ++i){
            for (int j = 0; j < 26; ++j){
                if (evil[i + 1] - 'a' == j)
                    fd[i + 1][j] = i + 1 + 1;
                else {
                    if (i == -1) fd[0][j] = 0;
                    else fd[i + 1][j] = fd[nxt[i] + 1][j];
                }
            }
        }
        int res1 = subp(n, s2, evil), res2 = subp(n, s1, evil);
        int ans = (res1 + M - res2) % M;
        // 补一个 check
        if (s1.find(evil) == string::npos) 
            ans = (ans + 1) % M;
        return ans;
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    Solution *solution = new Solution();
    std::cout << solution->minus("aca", "aba") << std::endl;
    return EXIT_SUCCESS;
}
