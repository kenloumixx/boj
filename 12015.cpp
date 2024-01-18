#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary_search(int num, int start, int end, vector<int>& numbers, vector<int>& lis);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    vector<int> numbers(num);
    for (int i = 0; i < num; i++) {
        cin >> numbers[i];
    }

    vector<int> lis(num, 1000005);
    for (int i = 0; i < num; i++) {
        binary_search(numbers[i], 0, num, numbers, lis);
    }

    auto it = find(lis.begin(), lis.end(), 1000005);
    cout << it - lis.begin() << '\n';
    return 0;
}

void binary_search(int num, int start, int end, vector<int>& numbers, vector<int>& lis) {
    if (start == end) {
        lis[start] = num;
        return;
    }
    int mid = (start + end) / 2;
    if (num < lis[mid]) {
        binary_search(num, start, mid, numbers, lis);
    } else if (num > lis[mid]) {
        if (start + 1 == end) {
            lis[end] = num;
            return;
        }
        binary_search(num, mid, end, numbers, lis);
    }
    return;
}

// binary search의 LIS는 nlogn