// URL    : https://leetcode-cn.com/problems/short-encoding-of-words/
// Author : Modnar
// Date   : 2020/03/28

#include <bits/stdc++.h>

/* ************************* */

// Failed: WRONG_ANSWER
// @ words = {"me", "time"};
class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string> &words) {
        std::string res;
        std::string::size_type pos;
        for (const std::string &word : words) {
            if ((pos = res.find(word)) != std::string::npos && 
                    res[pos+word.size()] == '#') {
                continue;
            } else {
                res += word + "#";
            }
        }
        return res.size();
    }
};

/* ************************* */

/**
 *     将每个单词逆序并降序排序，那么一个单词如果作为某个词的后缀出现，那么它的排序结
 * 果一定靠后；也就是说，包含该后缀单词的词，一定较该后缀词先出现！所以就可以使用上述
 * 遍历词表、查询单词是否存在于新的压缩串中并添加。
 */
namespace AnsOne {
    // Time: 480ms(34.84%)  Memory: 12.6MB(83.16%)
    class Solution {
    public:
        int minimumLengthEncoding(std::vector<std::string> &words) {
            std::string res;
            std::string::size_type pos;
            for (std::string &word : words)
                reverse(word);
            std::sort(words.begin(), words.end(), 
                    [](const std::string &a, const std::string &b) { return a > b; });
            for (const std::string &word : words)
                if ((pos = res.find(word)) != std::string::npos 
                        && res[pos-1] == '#') {
                    continue;
                } else {
                    res += "#" + word;
                }
            return res.size();
        }

    private:
        void reverse(std::string &s) {
            if (s.size() == 0) return;
            int i = 0, j = s.size()-1;
            while (i < j) {
                if (s[i] != s[j])
                    std::swap(s[i], s[j]);
                ++i, --j;
            }
        }
    };
}

/**
 *     判断每个后缀，如果它在words列表中，就将其从列表中删除。可以使用哈希集合来存储以
 * 实现高效存储。
 */
namespace AnsTwo {
    // Complexity: Time: O(sum(w[i]^2))  Space: O(sum(w[i]))
    // Time: 96ms(81.05%)  Memory: 15.4MB(46.32%)
    class Solution {
    public:
        int minimumLengthEncoding(std::vector<std::string> &words) {
            std::unordered_set<std::string> good(words.begin(), words.end());
            for (const std::string &word : words)
                for (int k = 1; k != word.size(); ++k)
                    good.erase(word.substr(k));
            int ans = 0;
            for (const std::string &word : good)
                ans += word.size() + 1;
            return ans;
        }
    };
}

/**
 * 使用Trie树存储单词的逆序串
 */
namespace AnsThree {
    // Time: 140ms(74.40%)  Memory: 85MB(15.79%)
    class TrieNode {
    private:
        std::vector<TrieNode *> children;

    public:
        int count;
        TrieNode() : children(26, nullptr), count(0) { }
        TrieNode *get(char c) {
            if (children[c-'a'] == nullptr) {
                children[c-'a'] = new TrieNode();
                ++count;
            }
            return children[c-'a'];
        }
    };

    class Solution {
    public:
        int minimumLengthEncoding(std::vector<std::string> &words) {
            TrieNode *trie = new TrieNode();
            std::unordered_map<TrieNode *, int> nodes;
            for (int i = 0; i != words.size(); ++i) {
                std::string word = words[i];
                TrieNode *curr = trie;
                for (int j = word.size()-1; j >= 0; --j)
                    curr = curr->get(word[j]);
                nodes[curr] = i;
            }
            int ans = 0;
            for (auto &[node, idx] : nodes)
                if (node->count == 0)
                    ans += words[idx].size() + 1;
            return ans;
        }
    };
}

int main(int argc, const char *argv[]) {
    using Solution = AnsTwo::Solution;
    std::vector<std::string> words = {"time", "me", "bell"};
    std::cout << (new Solution())->minimumLengthEncoding(words) << std::endl;
    // Ans: 10
    words = {"me", "time"};
    std::cout << (new Solution())->minimumLengthEncoding(words) << std::endl;
    // Ans: 5
    return EXIT_SUCCESS;
}
