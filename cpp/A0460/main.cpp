// URL    : https://leetcode-cn.com/problems/lfu-cache/
// Author : Modnar
// Date   : 2020/04/05
// Thanks : 前额叶没长好(@leetcode.cn)

#include <bits/stdc++.h>

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/* ************************* */

// Thanks: 前额叶没长好(@leetcode.cn)
// Solution: https://leetcode-cn.com/problems/lfu-cache/solution/c-ji-yu-unordered_maplist-shi-xian-o1-shi-jian-fu-/
// Time: 200ms(25.42%)  Memory: 39.5MB(40.00%)
class LFUCache {
    struct FreqNode;
    typedef std::list<FreqNode> FreqList;

    struct DataNode {
        int key;
        int value;
        FreqList::iterator fit;
        DataNode(int k = 0, int v = 0, FreqList::iterator f = FreqList::iterator())
            : key(k), value(v), fit(f) {}
    };
    typedef std::list<DataNode> DataList;

    struct FreqNode {
        int cnt;
        DataList dataList;
        FreqNode(int c = 0) : cnt(c) {}
    };
    FreqList cache;
    std::unordered_map<int, DataList::iterator> router;

    size_t capacity;

    void updateCache(int key) {
        //cout << "update " << key << endl;
        auto rit = router.find(key);
        auto it = rit->second;
        if(it->fit == cache.begin()) {
            cache.push_front(FreqNode(it->fit->cnt+1));
        } else {
            FreqList::iterator pre = it->fit; --pre;
            if(pre->cnt != it->fit->cnt+1) {
                cache.insert(it->fit, FreqNode(it->fit->cnt+1));
            }
        }
        auto curIt = it->fit;
        auto preIt = it->fit; --preIt;
        preIt->dataList.push_front(DataNode(key, it->value, preIt));
        curIt->dataList.erase(it);
        rit->second = preIt->dataList.begin();
    }

    void swapOut() {
        for(auto it = --cache.end(); ;) {
            if(it->dataList.size()) {
                auto out = it->dataList.back();
                router.erase(out.key);
                it->dataList.pop_back();
                break;
            } else {
                cache.erase(it--);
            }
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity) { }

    int get(int key) {
        auto it = router.find(key);
        if(it == router.end()) {
            return -1;
        }
        int val = it->second->value;
        updateCache(key);
        return val;
    }

    void put(int key, int value) {
        if(capacity == 0) {
            return;
        }
        auto rit = router.find(key);
        if(rit != router.end()) {
            rit->second->value = value;
            updateCache(key);
        } else {
            if(router.size() == capacity) {
                swapOut();
            }
            if(cache.empty() || cache.back().cnt != 1) {
                cache.push_back(FreqNode(1));
            }
            auto it = --cache.end();
            it->dataList.push_front(DataNode(key, value, it));
            router.insert(make_pair(key, it->dataList.begin()));
        }
    }
};

/* ************************* */

int main(int argc, const char *argv[]) {
    return EXIT_SUCCESS;
}
