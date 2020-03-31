#include <bits/stdc++.h>

bool inorder(const std::vector<int> &arr, int pos);

void process(const std::vector<int> &arr) {
    for (int i = 0; i < arr.size()-2; ++i)
        if (inorder(arr, i)) {
            std::cout << arr[i] << "->" << arr[i+2] << std::endl;
            i += 2;
        } else {
            std::cout << arr[i] << std::endl;
        }
}

bool inorder(const std::vector<int> &arr, int pos) {
    if (arr[pos]+1 == arr[pos+1] && arr[pos+1] == arr[pos+2]-1)
        return true;
    if (arr[pos]-1 == arr[pos+1] && arr[pos+1] == arr[pos+2]+1)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    std::vector<int> arr = {1, 2, 3, 5, 7, -2, -1, 0};
    process(arr);
    return EXIT_SUCCESS;
}
