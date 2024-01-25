#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num_miss;
    cin >> num_miss;

    vector<pair<int, int>> missiles(num_miss);
    for (int i = 0; i < num_miss; i++) {
        int start, end;
        cin >> start >> end;
        missiles[i].first = start;
        missiles[i].second = end;        
    }

    sort(missiles.begin(), missiles.end(), [](pair<int, int> data1, pair<int, int> data2){
        if (data1.second == data2.second) {
            return (data1.first < data2.first);
        }
        return (data1.second < data2.second);
    });
    
    int latest_end = 0;
    int num_need = 0;
    for (pair<int, int> missile: missiles) {
        int start = missile.first;
        int end = missile.second;
        if (start >= latest_end) {
            num_need++;
            latest_end = end;
        }
    }
    cout << num_need << '\n';
    return 0;
}

// 1. 정렬 후 앞에서부터 latest와 비교하기