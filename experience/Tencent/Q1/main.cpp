#include <bits/stdc++.h>

struct Item {
    Item(int k, int v) : key(k), value(v) { }
    int key;
    int value;
};

void print(std::vector<Item> &);

// For Function.1
void check(std::vector<Item> &arr) {
    for (int i = 0, j = 0; j != arr.size(); ++j)
        if (arr[j].key) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
}

// For Function.2
void process(std::vector<Item> &arr) {
    std::sort(arr.begin(), arr.end(), 
            [](const Item &a, const Item &b) { return a.value > b.value; });
}

// For DEBUG
void print(std::vector<Item> &arr) {
    for (const auto &it : arr)
        std::cout << it.key << " " << it.value << std::endl;
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    std::vector<Item> arr = {Item(1, 2), Item(3, 5), Item(6, 1), Item(0, 0), Item(7, 4), Item(0, 0), Item(0, 0), Item(4, 3), Item(0, 0)};
    // check(arr);
    process(arr);
    print(arr);
    return EXIT_SUCCESS;
}
