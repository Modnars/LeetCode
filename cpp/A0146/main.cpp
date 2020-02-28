// URL    : https://leetcode-cn.com/problems/lru-cache/
// Author : Modnar
// Date   : 2020/02/28
// Thanks : labuladong(@leetcode.cn)

#include <bits/stdc++.h>

/* ************************* */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Thanks: labuladong(@leetcode.cn)
// Time: 116ms(81.73%)  Memory: 41.9MB(5.07%)
class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) { }

    int get(int key) {
        auto iter = kpmap.find(key);
        // 访问的key不存在
        if (iter == kpmap.end()) return -1;
        // 访问的key存在，把(key, value)换到队头
        std::pair<int, int> kv = *kpmap[key];
        cache.erase(kpmap[key]);
        cache.push_front(kv);
        // 更新(key, value)在cache中的位置
        kpmap[key] = cache.begin();
        return kv.second; // value
    }

    void put(int key, int value) {
        auto iter = kpmap.find(key);
        // 先判断key是否已经存在
        if (iter == kpmap.end()) {
            // key不存在，判断cache是否已满
            if (cache.size() == capacity) {
                // cache已满，删除尾部的键值对
                // cache和kpmap中的相应数据要都删除
                auto last_pair = cache.back();
                int last_key = last_pair.first;
                kpmap.erase(last_key);
                cache.pop_back();
            }
            // cache未满，可以直接添加
            cache.push_front(std::make_pair(key, value));
            kpmap[key] = cache.begin();
        } else {
            // key存在，更改value并将其换到队头
            cache.erase(kpmap[key]);
            cache.push_front(std::make_pair(key, value));
            kpmap[key] = cache.begin();
        }
    }

private:
    int capacity;
    std::list<std::pair<int, int>> cache; // 双链表，装载着(key, value)元组
    // 哈希表: key映射到(key, value)在cache中的位置(position)
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> kpmap;
};

/* ************************* */

int main(int argc, const char *argv[]) {
    LRUCache *cache = new LRUCache( 2 /* 缓存容量 */ );
    cache->put(1, 1);
    cache->put(2, 2);
    std::cout << cache->get(1) << std::endl;    // Ans:  1
    cache->put(3, 3);
    std::cout << cache->get(2) << std::endl;    // Ans: -1 (未找到)
    cache->put(4, 4);
    std::cout << cache->get(1) << std::endl;    // Ans: -1 (未找到)
    std::cout << cache->get(3) << std::endl;    // Ans:  3
    std::cout << cache->get(4) << std::endl;    // Ans:  4

    std::cout << std::endl;
    cache = new LRUCache(2);
    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(4, 1);
    std::cout << cache->get(1) << std::endl;    // Ans: -1
    std::cout << cache->get(2) << std::endl;    // Ans: 3

    std::cout << std::endl;
    cache = new LRUCache(3);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    std::cout << cache->get(4) << std::endl;    // Ans: 4
    std::cout << cache->get(3) << std::endl;    // Ans: 3
    std::cout << cache->get(2) << std::endl;    // Ans: 2
    std::cout << cache->get(1) << std::endl;    // Ans: -1
    cache->put(5, 5);
    std::cout << cache->get(1) << std::endl;    // Ans: -1
    std::cout << cache->get(2) << std::endl;    // Ans: 2
    std::cout << cache->get(3) << std::endl;    // Ans: 3
    std::cout << cache->get(4) << std::endl;    // Ans: -1
    std::cout << cache->get(5) << std::endl;    // Ans: 5
    return EXIT_SUCCESS;
}
