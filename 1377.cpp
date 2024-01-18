#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr_len;
    cin >> arr_len;

    vector<pair<int, int>> arr(arr_len);

    for (int i = 0; i < arr_len; i++) {
        int num;
        cin >> num;
        arr[i] = make_pair(num, i); // value, idx
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> data1, pair<int, int> data2) {
        return (data1.first < data2.first); // data value 기준으로 sort
    });
    
    int max_diff = 0;
    for (int i = 0; i < arr.size(); i++) {
        max_diff = max(arr[i].second - i, max_diff);
    }
    cout << max_diff + 1 << '\n';
    return 0;
}


// 전체 원소 갯수 - 증가하는 수열 길이 + 1 (나머지는 전부 sorting에 의해 오른쪽 끝으로 정렬될 예정)
// LIS로 구하면 횟수 초과 -> DP대신 이진 탐색을 활용해야 한다! 
// 아 근데 LIS로 풀리는건 아니다.. -> i번째 원소가 왼쪽으로 이동하는건 버블소트에서 딱 한번만 가능!